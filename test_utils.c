#include <criterion/criterion.h>

#include "utils.h"

Test(test_utils, create_payload)
{
    struct payload *p = create_payload(10, SMALL, 1, 2);
    cr_assert_neq(p, NULL);
    cr_expect_eq(p->mass, 10);
    cr_expect_eq(p->diam, SMALL);
    cr_expect_eq(p->height, 1);
    cr_expect_eq(p->diameter, 2);
}

Test(test_utils, create_data)
{
    struct payload *payload = create_payload(10, SMALL, 1, 1);
    struct datas *d = create_data(payload, 1000, 0);
    cr_assert_neq(d, NULL);
    cr_expect_eq(d->deltaV_min, 1000);
    cr_expect_eq(d->cost_max, 0);
}
