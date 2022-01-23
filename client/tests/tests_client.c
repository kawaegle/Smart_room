/*
** EPITECH PROJECT, 2022
** client
** File description:
** you want a greek interogation point ;
*/

#include "../include/my.h"
#include "../include/client.h"
#include <criterion/criterion.h>
#include <criterion/hooks.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

Test(group_to_test, test_name)
{
    cr_assert_eq(function_to_test, value_expected);
}
