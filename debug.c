#include "utils.h"

int main(void)
{
    struct payload *payload = create_payload(10, SMALL, 1, 1);
    struct datas *d = create_data(payload, 1000, 0);
    free_datas(d);
    return 0;
}
