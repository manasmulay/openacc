#include <stdio.h>
#include <math.h>
 
float determinant(float[25][25],float);
void cofactor(float[25][25],float);
void transpose(float[25][25],float[25][25],float);
 
int main()
{
    float matrix[25][25],size,d;
    int i,j;
 
    // printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    // printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    // printf("\n* * * * * *                                                       * * * * * * *");
    // printf("\n* * * * * * THIS PROGRAM CALCULATE THE REVERSE OF SQUARE MATRIX ! * * * * * * *");
    // printf("\n* * * * * *                                                       * * * * * * *");
    // printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    // printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    // printf("\n\n  1 - Enter size of Matrix : ");
    scanf("%f",&size);
    // printf("\n  2 - Enter the elements of  Matrix : \n");
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
             // printf("\n\t[ %d , %d ] = ",i,j);
             scanf("%f",&matrix[i][j]);
        }
        printf("\n");
    }
    d=determinant(matrix,size);
    printf("\n\n    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\tDeterminant of the Matrix = %6.2f",d);
    if (d==0)
    {
        printf("\n\n    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\tInverse not exsist\n\n");
        printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n* * * * * * * * * * * * * * * * * THE END * * * * * * * * * * * * * * * * * * *");
        printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    }
    else
        cofactor(matrix,size);

}
 
/*For calculating Determinant of the Matrix . this function is recursive*/
float determinant(float matrix[25][25],float size)
{
    float s=1,det=0,m_minor[25][25];
    int i,j,m,n,c;
    if (size==1)
    {
        return (matrix[0][0]);
    }
    else
    {
        det=0;
        for (c=0;c<size;c++)
        {
            m=0;
            n=0;
            for (i=0;i<size;i++)
            {
                for (j=0;j<size;j++)
                {
                    m_minor[i][j]=0;
                    if (i != 0 && j != c)
                    {
                       m_minor[m][n]=matrix[i][j];
                       if (n<(size-2))
                          n++;
                       else
                       {
                           n=0;
                           m++;
                       }
                    }
                }
            }
            det=det + s * (matrix[0][c] * determinant(m_minor,size-1));
            s=-1 * s;
        }
    }
 
    return (det);
}
 
 /*calculate cofactor of matrix*/
void cofactor(float matrix[25][25],float size)
{
     float m_cofactor[25][25],matrix_cofactor[25][25];
     int p,q,m,n,i,j;
     for (q=0;q<size;q++)
     {
         for (p=0;p<size;p++)
         {
             m=0;
             n=0;
             for (i=0;i<size;i++)
             {
                 for (j=0;j<size;j++)
                 {
                     if (i != q && j != p)
                     {
                        m_cofactor[m][n]=matrix[i][j];
                        if (n<(size-2))
                           n++;
                        else
                        {
                            n=0;
                            m++;
                        }
                     }
                 }
             }
             matrix_cofactor[q][p]=pow(-1,q + p) * determinant(m_cofactor,size-1);
         }
     }
     transpose(matrix,matrix_cofactor,size);
}
 
/*Finding transpose of cofactor of matrix*/ 
void transpose(float matrix[25][25],float matrix_cofactor[25][25],float size)
{
     int i,j;
     float m_transpose[25][25],m_inverse[25][25],d;
 
     for (i=0;i<size;i++)
     {
         for (j=0;j<size;j++)
         {
             m_transpose[i][j]=matrix_cofactor[j][i];
         }
     }
     d=determinant(matrix,size);
     for (i=0;i<size;i++)
     {
         for (j=0;j<size;j++)
         {
             m_inverse[i][j]=m_transpose[i][j] / d;
         }
     }
     printf("\n\n\t* * * * * * * * * * * * * * * * * * * * * * * \n\n\tThe inverse of matrix is : \n\n");
 
     for (i=0;i<size;i++)
     {
         for (j=0;j<size;j++)
         {
             printf("\t%3.2f",m_inverse[i][j]);
         }
         printf("\n\n");
     }
     printf("\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
     printf("\n* * * * * * * * * * * * * * * * * THE END * * * * * * * * * * * * * * * * * * *");
     printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
}