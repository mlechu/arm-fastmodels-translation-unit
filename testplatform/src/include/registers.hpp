/**
 * Register Type Specifications
 *
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2022, Reto Achermann (The University of British Columbia)
 */

#ifndef _CONTROL_REGISTER_H_
#define _CONTROL_REGISTER_H_ 1

// generic includes
#include <framework/types.hpp>
#include <framework/register_base.hpp>

// translation unit specific includes
#include <state.hpp>

/**
 * @brief The ControlRegister class representing the control register of the unit
 */
class ControlRegister : public RegisterBase {
public:
    /**
     * @brief Constructor creating a new register object
     *
     * @param[in] state        pointer to the state object of the translation unit
     */
    ControlRegister(TranslationUnitState *state);

private:
    /**
     * @brief Performs the read operation (assumes permissions are checked)
     *
     * @return the value of the register
     */
    uint64_t do_read(void) override;


    /**
     * @brief Performs the write operation (assumes permissions are checked)
     *
     * @param[in] data  the data to be written
     */
    void do_write(uint64_t data) override;
};


/**
 * @brief The BaseRegister class representing the base address register of the unit
 */
class BaseRegister : public RegisterBase {
public:
    /**
     * @brief Constructor creating a new register object
     *
     * @param[in] state    pointer to the state object of the translation unit
     * @param[in] idx     the index of the register in the array
     */
    BaseRegister(TranslationUnitState *state, size_t idx);

private:
    /**
     * @brief Performs the read operation (assumes permissions are checked)
     *
     * @return the value of the register
     */
    uint64_t do_read(void) override;


    /**
     * @brief Performs the write operation (assumes permissions are checked)
     *
     * @param[in] data  the data to be written
     */
    void do_write(uint64_t data) override;
};


/**
 * @brief The SizeRegister class representing the size register of the unit
 */
class SizeRegister : public RegisterBase {
public:
    /**
     * @brief Constructor creating a new register object
     *
     * @param[in] state        pointer to the state object of the translation unit
     */
    SizeRegister(TranslationUnitState *state, size_t idx);

private:
    /**
     * @brief Performs the read operation (assumes permissions are checked)
     *
     * @return the value of the register
     */
    uint64_t do_read(void) override;


    /**
     * @brief Performs the write operation (assumes permissions are checked)
     *
     * @param[in] data  the data to be written
     */
    void do_write(uint64_t data) override;
};


/**
 * @brief The FlagsRegister class representing the flags register of the unit
 */
class FlagsRegister : public RegisterBase {
public:
    /**
     * @brief Constructor creating a new register object
     *
     * @param[in] state        pointer to the state object of the translation unit
     */
    FlagsRegister(TranslationUnitState *state, size_t idx);

private:
    /**
     * @brief Performs the read operation (assumes permissions are checked)
     *
     * @return the value of the register
     */
    uint64_t do_read(void) override;


    /**
     * @brief Performs the write operation (assumes permissions are checked)
     *
     * @param[in] data  the data to be written
     */
    void do_write(uint64_t data) override;
};

#endif /* _CONTROL_REGISTER_H_ */