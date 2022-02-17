/**
 * Translation Unit Interface class implementation
 *
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2022, Reto Achermann (The University of British Columbia)
 */

#include "pv/RemapRequest.h"

// generic includes
#include <framework/logging.hpp>

// translation unit specific includes
#include <registers.hpp>
#include <interface.hpp>


TranslationUnitInterface::TranslationUnitInterface(TranslationUnitState *state)
    : InterfaceBase(state)
    , _state(state)
    , _reg_ctrl(ControlRegister(_state))
    , _reg_base {
        BaseRegister(_state, 0),
        BaseRegister(_state, 1),
        BaseRegister(_state, 2),
        BaseRegister(_state, 3),
    }
    , _reg_size {
        SizeRegister(_state, 0),
        SizeRegister(_state, 1),
        SizeRegister(_state, 2),
        SizeRegister(_state, 3),
    }
    , _reg_flags {
        FlagsRegister(_state, 0),
        FlagsRegister(_state, 1),
        FlagsRegister(_state, 2),
        FlagsRegister(_state, 3),
    }
{
    this->add_register(&this->_reg_ctrl);
    for (size_t i = 0; i < CONFIG_NUM_TRANSLATION_REGISTERS; i++) {
        this->add_register(&this->_reg_base[i]);
        this->add_register(&this->_reg_size[i]);
        this->add_register(&this->_reg_flags[i]);
    }
}
