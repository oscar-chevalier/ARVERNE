#include "structures/datas.h"
#include "structures/payload.h"

int main(void)
{
    struct payload *payload = create_payload(10, SMALL, 1, 1);
    struct datas *d = create_datas(payload, 1000, 0);
    free_datas(d);
    return 0;
}
