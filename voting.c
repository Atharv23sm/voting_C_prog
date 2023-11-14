#include <stdio.h>
#include <stdlib.h>

struct vote
{
    int num;
    char cand[20];
    char party[20];
    int count;
    struct vote *link;
} *head = 0, *tail, *p;

int n, vot, choice, pass = 1234;

void create_candidate_list(int i)
{
    p = malloc(sizeof(struct vote));
    p->link = 0;
    p->count = 0;
    printf("\nEnter name of a candidate : ");
    scanf("%s", p->cand);
    printf("Enter name of candidate's party : ");
    scanf("%s", p->party);
    p->num = i + 1;

    if (head == 0)
    {
        head = tail = p;
    }

    else
    {
        tail->link = p;
        tail = p;
    }
}

void disp_count()
{
    p = head;

    while (p)
    {
        printf("\n%s - %d\n", p->cand, p->count);
        p = p->link;
    }
}

void vote()
{
    p = head;

    printf("\nNo. | Candidate | Party\n\n");

    while (p)
    {
        printf("%d - %s - %s\n", p->num, p->cand, p->party);
        p = p->link;
    }

    printf("\nEnter the number of candidate as your vote : ");
    scanf("%d", &vot);

    if (vot <= n)
    {
        p = head;
        for (int i = 0; i < vot - 1; i++)
        {
            p = p->link;
        }

        p->count++;

        printf("\nVoted Successfully\n");
    }
    else
    {
        printf("\nInvalid vote!\n");
    }
}

void password_confirmation()
{
    printf("\nEnter Password : ");
    scanf("%d", &vot);

    if (pass == vot)
    {
        disp_count();
    }
    else
    {
        printf("Incorrect Password!\n");
    }
}

void exit_confirmation()
{
    printf("Confirmation : Yes(1) No(0) : ");
    scanf("%d", &vot);

    if (vot == 1)
    {
        disp_count();

        exit(0);
    }
}

int main()
{
    printf("Welcome!\nYou're currently using voting system made with C programming language.\n\nEnter number of candidates : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        create_candidate_list(i);
    }

    while (1)
    {
        printf("\n1 : Vote\n2 : See Vote Count\n3 : Exit\nEnter : ");

        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            vote();

            break;

        case 2:

            password_confirmation();

            break;

        case 3:

            exit_confirmation();

            break;
        }
    }

    return 0;
}