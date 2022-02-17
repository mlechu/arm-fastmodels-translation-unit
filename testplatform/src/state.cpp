/**
 * Translation Unit State class implementation
 *
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2022, Reto Achermann (The University of British Columbia)
 */

#include <vector>

#include "pv/RemapRequest.h"

// generic includes
#include <framework/logging.hpp>
#include <framework/state_field_base.hpp>

// translation unit specific includes
#include <state.hpp>


TranslationUnitState::TranslationUnitState(void)
    : StateBase()
    , _control(StateFieldBase(CONFIG_CONTROL_FIELD_NAME, 32, 0))
    , _base {
        StateFieldBase(CONFIG_BASE_FIELD_NAME(0), 64, 0),
        StateFieldBase(CONFIG_BASE_FIELD_NAME(1), 64, 0),
        StateFieldBase(CONFIG_BASE_FIELD_NAME(2), 64, 0),
        StateFieldBase(CONFIG_BASE_FIELD_NAME(3), 64, 0),
    }
    , _size {
        StateFieldBase(CONFIG_SIZE_FIELD_NAME(0), 64, 0),
        StateFieldBase(CONFIG_SIZE_FIELD_NAME(1), 64, 0),
        StateFieldBase(CONFIG_SIZE_FIELD_NAME(2), 64, 0),
        StateFieldBase(CONFIG_SIZE_FIELD_NAME(3), 64, 0),
    }
    , _flags {
        StateFieldBase(CONFIG_FLAGS_FIELD_NAME(0), 32, 0),
        StateFieldBase(CONFIG_FLAGS_FIELD_NAME(1), 32, 0),
        StateFieldBase(CONFIG_FLAGS_FIELD_NAME(2), 32, 0),
        StateFieldBase(CONFIG_FLAGS_FIELD_NAME(3), 32, 0),
    }
{
    this->add_field(&this->_control);
    for (size_t i = 0; i < CONFIG_NUM_TRANSLATION_FIELDS; i++) {
        this->add_field(&this->_base[i]);
        this->add_field(&this->_size[i]);
        this->add_field(&this->_flags[i]);
    }
}
