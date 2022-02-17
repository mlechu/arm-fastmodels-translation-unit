/**
 * Translation Unit class implementation
 *
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2022, Reto Achermann (The University of British Columbia)
 */

// generic includes
#include <framework/logging.hpp>

// translation unit specific uncludes
#include <interface.hpp>
#include <unit.hpp>

TranslationUnit::TranslationUnit(std::string const                     &name,
                                 pv::RandomContextTransactionGenerator *ptw_pvbus)
    : TranslationUnitBase(name, ptw_pvbus, 0, CONFIG_END_ADDRESS)
    , _state(TranslationUnitState())
    , _interface(TranslationUnitInterface(&_state))
{
}

TranslationUnit *TranslationUnit::create(sg::ComponentBase *parentComponent,
                                         std::string const &name, sg::CADIBase *cadi,
                                         pv::RandomContextTransactionGenerator *ptw_pvbus)
{
    Logging::debug("creating new translation unit.\n");

    TranslationUnit *t = new TranslationUnit(name, ptw_pvbus);

    t->_state.print_state_fields();
    t->_interface.debug_print_interface();


    Logging::debug("translation unit created.\n");

    return t;
}


/*
 * -------------------------------------------------------------------------------------------
 * Translations
 * -------------------------------------------------------------------------------------------
 */

bool TranslationUnit::do_translate(lvaddr_t src_addr, size_t size, access_mode_t mode,
                                   lpaddr_t *dst_addr)
{
    Logging::debug("TranslationUnit::do_translate()");

    uint64_t val;
    if (this->translation_table_walk(0x1000, 64, &val)) {
        Logging::debug("SSSSS: page table walk returned: 0x%lx", val);
    } else {
        Logging::debug("SSSSS: Failed to do the page table walk.");
    }


    auto ctrl = this->_state.control_field();
    if (!(ctrl->get_value() & 0x1)) {
        Logging::debug("TranslationUnit::translate() - disabled. don't remap. %x");
        *dst_addr = src_addr;
        return true;
    }

    size_t idx    = src_addr / CONFIG_TRANSLATION_BLOCK_SIZE;
    size_t offset = src_addr % CONFIG_TRANSLATION_BLOCK_SIZE;

    assert(idx < CONFIG_NUM_TRANSLATION_REGISTERS);

    lpaddr_t segbase = this->_state.get_base_field_n_value(idx);
    size_t   segsize = this->_state.get_size_field_n_value(idx);

    if (offset >= segsize) {
        Logging::debug("TranslationUnit::translate() - offset >= size ", src_addr, size);
        return false;
    }

    if (idx >= CONFIG_NUM_TRANSLATION_REGISTERS) {
        Logging::debug("TranslationUnit::translate() - idx %zu >= "
                       "CONFIG_NUM_TRANSLATION_REGISTERS %u",
                       idx, CONFIG_NUM_TRANSLATION_REGISTERS);
        return false;
    }

    // set the return address
    *dst_addr = segbase + offset;

    return true;
}


/**
 * handles a DVM message from the downstream port
 *
 * @param[in]   msg    the DVM message
 * @param[out]  ptw    whether the message was received on the page walker port
 */
DVM::error_response_t TranslationUnit::handle_dvm_msg(DVM::Message *msg, bool ptw)
{
    Logging::debug("TranslationUnit::translate()");
    return DVM::error_response_t(DVM::error_response_t::ok);
}