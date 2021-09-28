#include<bits/stdc++.h>

using namespace std;

#define N 300

int n;
double mat[N][N+1];


void swap_row(int i, int j)
{


    for (int k=0; k<=n; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

void print()
{
    for (int i=0; i<n; i++, printf("\n"))
        for (int j=0; j<=n; j++)
            printf("%lf ", mat[i][j]);

    printf("\n");
}



int forwardElim()
{
    for (int k=0; k<n; k++)
    {

        int i_max = k;
        int v_max = mat[i_max][k];


        for (int i = k+1; i < n; i++)
            if (abs(mat[i][k]) > v_max)
                v_max = mat[i][k], i_max = i;


        if (!mat[k][i_max])
            return k;
        if (i_max != k)
            swap_row(k, i_max);


        for (int i=k+1; i<n; i++)
        {

            double f = mat[i][k]/mat[k][k];

            for (int j=k+1; j<=n; j++)
                mat[i][j] -= mat[k][j]*f;


            mat[i][k] = 0;
        }

    }

    return -1;
}

void backSub()
{
    double x[n];


    for (int i = n-1; i >= 0; i--)
    {x[i] = mat[i][n];


        for (int j=i+1; j<n; j++)
        {

            x[i] -= mat[i][j]*x[j];
        }
        x[i] = x[i]/mat[i][i];
    }

    printf("\nSolution for the system:\n");
    for (int i=0; i<n; i++)
        printf("%lf\n", x[i]);
}


void gaussianElimination()
{

    int singular_flag = forwardElim();

    if (singular_flag != -1)
    {
        printf("Singular Matrix.\n");


        if (mat[singular_flag][n])
            printf("Inconsistent System.");
        else
            printf("May have infinitely many "
                   "solutions.");

        return;
    }

    backSub();
}




int main()
{

    freopen("code.in","r",stdin);
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
            cin >> mat[i][j];

    gaussianElimination();

    return 0;
}

