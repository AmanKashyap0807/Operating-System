#include <stdio.h>
#define MAX 25

void firstFit(int nb, int nf, int b[], int f[])
{
    int frag[MAX], bf[MAX] = {0}, ff[MAX];
    printf("\n\nFirst Fit Allocation:");
    for (int i = 0; i < nf; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if (bf[j] != 1 && b[j] >= f[i])
            {
                ff[i] = j + 1;
                frag[i] = b[j] - f[i];
                bf[j] = 1;
                break;
            }
        }
    }
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (int i = 0; i < nf; i++)
    {
        if (ff[i] != 0)
        {
            printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",
                   i + 1, f[i], ff[i], b[ff[i] - 1], frag[i]);
        }
        else
        {
            printf("\n%d\t%d\t\tNot Allocated", i + 1, f[i]);
        }
    }
}

void bestFit(int nb, int nf, int b[], int f[])
{
    int frag[MAX], bf[MAX] = {0}, ff[MAX];
    printf("\n\nBest Fit Allocation:");
    for (int i = 0; i < nf; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < nb; j++)
        {
            if (bf[j] == 0 && b[j] >= f[i])
            {
                if (bestIdx == -1 || b[j] < b[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1)
        {
            ff[i] = bestIdx + 1;
            frag[i] = b[bestIdx] - f[i];
            bf[bestIdx] = 1;
        }
    }
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (int i = 0; i < nf; i++)
    {
        if (ff[i] != 0)
        {
            printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",
                   i + 1, f[i], ff[i], b[ff[i] - 1], frag[i]);
        }
        else
        {
            printf("\n%d\t%d\t\tNot Allocated", i + 1, f[i]);
        }
    }
}

void worstFit(int nb, int nf, int b[], int f[])
{
    int frag[MAX], bf[MAX] = {0}, ff[MAX];
    printf("\n\nWorst Fit Allocation:");
    for (int i = 0; i < nf; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < nb; j++)
        {
            if (bf[j] == 0 && b[j] >= f[i])
            {
                if (worstIdx == -1 || b[j] > b[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1)
        {
            ff[i] = worstIdx + 1;
            frag[i] = b[worstIdx] - f[i];
            bf[worstIdx] = 1;
        }
    }
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (int i = 0; i < nf; i++)
    {
        if (ff[i] != 0)
        {
            printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",
                   i + 1, f[i], ff[i], b[ff[i] - 1], frag[i]);
        }
        else
        {
            printf("\n%d\t%d\t\tNot Allocated", i + 1, f[i]);
        }
    }
}

int main()
{
    int nb, nf, b[MAX], f[MAX];

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);
    printf("Enter block sizes:\n");
    for (int i = 0; i < nb; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("Enter number of files: ");
    scanf("%d", &nf);
    printf("Enter file sizes:\n");
    for (int i = 0; i < nf; i++)
    {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    firstFit(nb, nf, b, f);
    bestFit(nb, nf, b, f);
    worstFit(nb, nf, b, f);

    return 0;
}
