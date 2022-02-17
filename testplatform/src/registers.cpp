/**
 * The Register Base Class of the Translation Unit
 *
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2022, Reto Achermann (The University of British Columbia)
 */

// generic includes
#include <framework/logging.hpp>
#include <framework/types.hpp>

// translation unit specific includes
#include <registers.hpp>

/*
 * -----------------------------------------------------------------------------------------------
 * Control Register
 * -----------------------------------------------------------------------------------------------
 */

#define CONTROL_REGISTER_BASE_ADDRESS 0x0
#define CONTROL_REGISTER_WIDTH        4
#define CONTROL_REGISTER_PERMS        ACCESS_PERMISSION_ALL
#define CONTROL_REGISTER_VALUE        0x0

ControlRegister::ControlRegister(TranslationUnitState *state)
    : RegisterBase("control", CONTROL_REGISTER_BASE_ADDRESS, CONTROL_REGISTER_WIDTH,
                   CONTROL_REGISTER_PERMS, CONTROL_REGISTER_VALUE, state)
{
}

uint64_t ControlRegister::do_read(void)
{
    Logging::debug("ControlRegister::do_read()");
    auto st = static_cast<TranslationUnitState *>(this->get_state());
    return st->control_field()->get_value();
}


void ControlRegister::do_write(uint64_t value)
{
    Logging::debug("ControlRegister::do_write() = 0%lx", this->get_idx(), value);
    auto st = static_cast<TranslationUnitState *>(this->get_state());
    st->control_field()->set_value(value);
}

/*
 * -----------------------------------------------------------------------------------------------
 * Base Register
 * -----------------------------------------------------------------------------------------------
 */

#define BASE_REGISTER_BASE_ADDRESS(idx) (0x8 + idx * 0x20)
#define BASE_REGISTER_WIDTH             8
#define BASE_REGISTER_PERMS             ACCESS_PERMISSION_ALL
#define BASE_REGISTER_VALUE             0x0

BaseRegister::BaseRegister(TranslationUnitState *state, size_t idx)
    : RegisterBase("base", idx, BASE_REGISTER_BASE_ADDRESS(idx), BASE_REGISTER_WIDTH,
                   BASE_REGISTER_PERMS, BASE_REGISTER_VALUE, state)
{
}

uint64_t BaseRegister::do_read(void)
{
    Logging::debug("BaseRegister::do_read(%zu)", this->get_idx());
    auto st = static_cast<TranslationUnitState *>(this->get_state());
    return st->base_field_n(this->get_idx())->get_value();
}


void BaseRegister::do_write(uint64_t value)
{
    Logging::debug("BaseRegister::do_write(%zu) = 0x%lx", this->get_idx(), value);
    auto st = static_cast<TranslationUnitState *>(this->get_state());
    st->base_field_n(this->get_idx())->set_value(value);
}


/*
 * -----------------------------------------------------------------------------------------------
 * Base Register
 * -----------------------------------------------------------------------------------------------
 */

#define SIZE_REGISTER_BASE_ADDRESS(idx) (0x8 + 0x8 + idx * 0x20)
#define SIZE_REGISTER_WIDTH             8
#define SIZE_REGISTER_PERMS             ACCESS_PERMISSION_ALL
#define SIZE_REGISTER_VALUE             0x0


SizeRegister::SizeRegister(TranslationUnitState *state, size_t idx)
    : RegisterBase("size", idx, SIZE_REGISTER_BASE_ADDRESS(idx), SIZE_REGISTER_WIDTH,
                   SIZE_REGISTER_PERMS, SIZE_REGISTER_VALUE, state)
{
}

uint64_t SizeRegister::do_read(void)
{
    Logging::debug("SizeRegister::do_read(%zu)", this->get_idx());
    auto st = static_cast<TranslationUnitState *>(this->get_state());
    return st->size_field_n(this->get_idx())->get_value();
}


void SizeRegister::do_write(uint64_t value)
{
    Logging::debug("SizeRegister::do_write(%zu) = 0x%lx", this->get_idx(), value);
    auto st = static_cast<TranslationUnitState *>(this->get_state());
    st->size_field_n(this->get_idx())->set_value(value);
}


/*
 * -----------------------------------------------------------------------------------------------
 * Base Register
 * -----------------------------------------------------------------------------------------------
 */

#define FLAGS_REGISTER_BASE_ADDRESS(idx) (0x8 + 0x10 + idx * 0x20)
#define FLAGS_REGISTER_WIDTH             8
#define FLAGS_REGISTER_PERMS             ACCESS_PERMISSION_ALL
#define FLAGS_REGISTER_VALUE             0x0


FlagsRegister::FlagsRegister(TranslationUnitState *state, size_t idx)
    : RegisterBase("flags", idx, FLAGS_REGISTER_BASE_ADDRESS(idx), FLAGS_REGISTER_WIDTH,
                   FLAGS_REGISTER_PERMS, FLAGS_REGISTER_VALUE, state)
{
}

uint64_t FlagsRegister::do_read(void)
{
    Logging::debug("FlagsRegister::do_read(%zu)", this->get_idx());
    auto st = static_cast<TranslationUnitState *>(this->get_state());
    return st->flags_field_n(this->get_idx())->get_value();
}


void FlagsRegister::do_write(uint64_t value)
{
    Logging::debug("FlagsRegister::do_write(%zu) = 0x%lx", this->get_idx(), value);
    auto st = static_cast<TranslationUnitState *>(this->get_state());
    st->flags_field_n(this->get_idx())->set_value(value);
}