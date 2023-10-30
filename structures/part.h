#ifndef ARVERNE_PART_H
#define ARVERNE_PART_H

struct part
{
    void *part_type;
    struct part *prev;
    struct part *next;
};

#endif //ARVERNE_PART_H
