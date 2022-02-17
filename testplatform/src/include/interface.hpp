/**
 * The Interface of the Translation Unit
 *
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2022, Reto Achermann (The University of British Columbia)
 */

#ifndef _TRANSLATION_UNIT_INTERFACE_H_
#define _TRANSLATION_UNIT_INTERFACE_H_ 1

#include <map>
#include <stddef.h>

// generic includes
#include <framework/types.hpp>
#include <framework/interface_base.hpp>

// translation unit specific includes
#include <state.hpp>
#include <registers.hpp>


#define CONFIG_NUM_TRANSLATION_REGISTERS 4
#define CONFIG_TRANSLATION_BLOCK_SIZE    (1 << 20)
#define CONFIG_END_ADDRESS               (CONFIG_NUM_TRANSLATION_REGISTERS * CONFIG_TRANSLATION_BLOCK_SIZE)


#define CONFIG_CONTROL_REGISTER_NAME "control"

#define CONFIG_BASE_REGISTER_NAME(idx)  "base" STRINGIFY(idx)
#define CONFIG_SIZE_REGISTER_NAME(idx)  "size" STRINGIFY(idx)
#define CONFIG_FLAGS_REGISTER_NAME(idx) "flags" STRINGIFY(idx)


class TranslationUnitInterface : public InterfaceBase {
public:
    /**
     * @brief constructor of the translation unit interface
     *
     * @param[in] state     pointer to the state variable
     */
    TranslationUnitInterface(TranslationUnitState *state);


private:
    ///< the state of the translation unit
    TranslationUnitState *_state;

    ///< the control register
    ControlRegister _reg_ctrl;

    ///< the base registers
    BaseRegister _reg_base[CONFIG_NUM_TRANSLATION_REGISTERS];

    ///< the size registers
    SizeRegister _reg_size[CONFIG_NUM_TRANSLATION_REGISTERS];

    ///< the flags registers
    FlagsRegister _reg_flags[CONFIG_NUM_TRANSLATION_REGISTERS];
};

#endif  // _TRANSLATION_UNIT_INTERFACE_H_