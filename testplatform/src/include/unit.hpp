/**
 * My Translation Unit Class
 *
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2022, Reto Achermann (The University of British Columbia)
 */

#ifndef _TRANSLATION_UNIT_H_
#define _TRANSLATION_UNIT_H_ 1

#include <string>

// generic includes
#include <framework/translation_unit_base.hpp>

// translation unit specific includes
#include <state.hpp>
#include <interface.hpp>

// forward declaration

/**
 * This namespace defines the public interfaces to the TranslationUnit model.
 */
class TranslationUnit : public TranslationUnitBase {
public:
    /**
     * @brief creates a new TranslationUnit object
     *
     * @param[in] parentComponent    pointer to the parent component
     * @param[in] name               name of the translation unit
     * @param[in] cadi               pointer to the cadi base instance
     */
    static TranslationUnit *create(sg::ComponentBase *parentComponent, std::string const &name,
                                   sg::CADIBase                          *cadi,
                                   pv::RandomContextTransactionGenerator *ptw_pvbus);


    /*
     * -------------------------------------------------------------------------------------------
     * Accessors
     * -------------------------------------------------------------------------------------------
     */


    /**
     * @brief obtains a pointer to the interface
     *
     * @returns pointer ot the interface of the unit
     */
    virtual InterfaceBase *get_interface(void) override
    {
        return &this->_interface;
    }

    /**
     * @brief obtains a pointer to the state
     *
     * @returns pointer to the state
     */
    virtual StateBase *get_state(void) override
    {
        return &this->_state;
    }


    /*
     * -------------------------------------------------------------------------------------------
     * Translations
     * -------------------------------------------------------------------------------------------
     */


    /**
     * @brief translates the address
     *
     * @param[in]  src_addr  the source virtual address to be translated
     * @param[in]  size      the size of the translation request
     * @param[in]  mode      the mode of the request
     * @param[out] dst_addr  the translated address
     *
     * @returns true if the translation was successful, false otherwise
     */
    virtual bool do_translate(lvaddr_t src_addr, size_t size, access_mode_t mode,
                              lpaddr_t *dst_addr) override;


    /**
     * handles a DVM message from the downstream port
     *
     * @param[in]   msg    the DVM message
     * @param[out]  ptw    whether the message was received on the page walker port
     */
    virtual DVM::error_response_t handle_dvm_msg(DVM::Message *msg, bool ptw) override;

private:
    TranslationUnit(std::string const                     &name,
                    pv::RandomContextTransactionGenerator *ptw_pvbus = nullptr);

    TranslationUnitState     _state;
    TranslationUnitInterface _interface;
};

#endif /* _TRANSLATION_UNIT_H_ */