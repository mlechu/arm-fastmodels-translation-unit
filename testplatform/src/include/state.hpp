/**
 * The State of the Translation Unit
 *
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2022, Reto Achermann (The University of British Columbia)
 */

#ifndef _TRANSLATION_UNIT_STATE_H_
#define _TRANSLATION_UNIT_STATE_H_ 1

#include <stddef.h>
#include <assert.h>

// generic includes
#include <framework/types.hpp>
#include <framework/state_base.hpp>

///< the number of translation fields (base, size, flags)
#define CONFIG_NUM_TRANSLATION_FIELDS 4


#define CONFIG_CONTROL_FIELD_NAME "control"

#define CONFIG_BASE_FIELD_NAME(idx)  "base" STRINGIFY(idx)
#define CONFIG_SIZE_FIELD_NAME(idx)  "size" STRINGIFY(idx)
#define CONFIG_FLAGS_FIELD_NAME(idx) "flags" STRINGIFY(idx)

/**
 * @brief describes the state of the translation unit
 *
 * The state of the translation unit describes *how* it translates addresses.
 */
class TranslationUnitState : public StateBase {
public:
    /**
     * @brief Constructor creating a new state object
     */
    TranslationUnitState();


    /*
     * -------------------------------------------------------------------------------------------
     * Control field
     * -------------------------------------------------------------------------------------------
     */


    /**
     * @brief updates the current value in the control field
     *
     * @param[in] value  the data to be written
     *
     * @return true if the value was updated, false otherwise
     */
    void set_control_value(uint32_t value)
    {
        this->_control.set_value(value);
    }


    /**
     * @brief obtains the current value in the control field
     *
     * @return the current value of the control field
     */
    uint32_t get_control_value(void)
    {
        return this->_control.get_value();
    }


    /**
     * @brief obtais a pointer to the control FIELD
     *
     * @returns pointer to the field object
     */
    StateFieldBase *control_field(void)
    {
        return &this->_control;
    }


    /*
     * -------------------------------------------------------------------------------------------
     * Translation Fields: Base
     * -------------------------------------------------------------------------------------------
     */


    /**
     * @brief obtains the current value in the base field
     *
     * @param[in] idx  index of the base field
     *
     * @return the current value of the base field
     */
    lpaddr_t get_base_field_n_value(size_t idx)
    {
        assert(idx < CONFIG_NUM_TRANSLATION_FIELDS);
        return (lpaddr_t)this->_base[idx].get_value();
    }


    /**
     * @brief sets the current value in the base field
     *
     * @param[in] idx   index of the base field
     * @param[in] base  the base address to be written
     */
    void set_base_field_n_value(size_t idx, lpaddr_t base)
    {
        assert(idx < CONFIG_NUM_TRANSLATION_FIELDS);
        this->_base[idx].set_value(base);
    }


    /**
     * @brief obtains a pointer to the base field
     *
     * @param[in] idx  index of the base field
     *
     * @returns pointer to the field object
     */
    StateFieldBase *base_field_n(size_t idx)
    {
        assert(idx < CONFIG_NUM_TRANSLATION_FIELDS);
        return &this->_base[idx];
    }


    /*
     * -------------------------------------------------------------------------------------------
     * Translation Fields: Size
     * -------------------------------------------------------------------------------------------
     */

    /**
     * @brief obtains the current value in the size field
     *
     * @param[in] idx  index of the size field
     *
     * @return the current value of the size field
     */
    size_t get_size_field_n_value(size_t idx)
    {
        assert(idx < CONFIG_NUM_TRANSLATION_FIELDS);
        return (size_t)this->_size[idx].get_value();
    }


    /**
     * @brief sets the current value in the size field
     *
     * @param[in] idx   index of the size field
     * @param[in] size  the size to be written
     */
    void set_size_field_n_value(size_t idx, size_t size)
    {
        assert(idx < CONFIG_NUM_TRANSLATION_FIELDS);
        this->_size[idx].set_value(size);
    }


    /**
     * @brief obtains a pointer to the size field
     *
     * @param[in] idx  index of the size field
     *
     * @returns pointer to the field object
     */
    StateFieldBase *size_field_n(size_t idx)
    {
        assert(idx < CONFIG_NUM_TRANSLATION_FIELDS);
        return &this->_size[idx];
    }


    /*
     * -------------------------------------------------------------------------------------------
     * Translation Field: Flags
     * -------------------------------------------------------------------------------------------
     */


    /**
     * @brief obtains the current value in the flags field
     *
     * @param[in] idx  index of the flags field
     *
     * @return the current value of the flags field
     */
    uint64_t get_flags_field_n_value(size_t idx)
    {
        assert(idx < CONFIG_NUM_TRANSLATION_FIELDS);
        return this->_flags[idx].get_value();
    }

    /**
     * @brief sets the current value in the flags field
     *
     * @param[in] idx   index of the flags field
     * @param[in] flags the flags to be written
     */
    void set_flags_field_n_value(size_t idx, uint64_t flags)
    {
        assert(idx < CONFIG_NUM_TRANSLATION_FIELDS);
        this->_flags[idx].set_value(flags);
    }


    /**
     * @brief obtains a pointer to the flags field
     *
     * @param[in] idx  index of the flags field
     *
     * @returns pointer to the field object
     */
    StateFieldBase *flags_field_n(size_t idx)
    {
        assert(idx < CONFIG_NUM_TRANSLATION_FIELDS);
        return &this->_flags[idx];
    }


private:
    /*
     * -------------------------------------------------------------------------------------------
     * The fields of the state
     * -------------------------------------------------------------------------------------------
     */

    ///< the control field
    StateFieldBase _control;

    ///< the bases fields
    StateFieldBase _base[CONFIG_NUM_TRANSLATION_FIELDS];

    ///< sizes fields
    StateFieldBase _size[CONFIG_NUM_TRANSLATION_FIELDS];

    ///< the flags fields
    StateFieldBase _flags[CONFIG_NUM_TRANSLATION_FIELDS];
};

#endif  // _TRANSLATION_UNIT_STATE_H_