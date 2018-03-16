#include <iostream>
#include "matrix.h"

matrix::matrix(int a, int b)
{
    rows=a;
    columns=b;
    int** tab;
    tab = new int* [rows];
    int i;
    for(i = 0; i <= rows; i++)
        tab[i] = new int [columns];
    value = tab;

}

ostream& operator<<(ostream &os,matrix &m)
{
    for(int i=1; i<=m.rows; i++)
    {
        for(int j=1; j<=m.columns; j++)
        {
            os<<m.value[i][j]<<' ';
        }
        os<<endl;
    }
}

matrix matrix::operator+(matrix &b)
{
    matrix result(rows,columns);
    if(rows==b.rows&&columns==b.columns)
    {
        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=columns; j++)
            {
                result.value[i][j]=(value[i][j]+b.value[i][j]);
            }
        }
        return result;
    }else{
    cout<<"Matrix dimensions are not correct.";

    }

}

bool matrix::operator==(matrix &b)
{
    if(rows==b.rows&&columns==b.columns)
    {
        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=columns; j++)
            {
                if(value[i][j]!=b.value[i][j]){
                return 0;
                }
            }
        }
        return 1;
    }else{
    return 0;

    }

}

istream& operator>>(istream &is,matrix &m){
cout<<"Insert "<<m.columns<<" value(s) in each row."<<endl;
for(int i=1; i<=m.rows; i++)
        {
        cout<<i<<": ";
            for(int j=1; j<=m.columns; j++)
            {
            is>>m.value[i][j];
            }
        }

}

bool matrix::operator!=(matrix &b)
{
    return !matrix::operator==(b);

}

void matrix::operator+=(matrix &b){
if(rows==b.rows&&columns==b.columns)
    {
        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=columns; j++)
            {
                value[i][j]=(value[i][j]+b.value[i][j]);
            }
        }
    }else{
    cout<<"Matrix dimensions are not correct.";

    }
}

matrix matrix::operator-(matrix &b)
{
    matrix result(rows,columns);
    if(rows==b.rows&&columns==b.columns)
    {
        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=columns; j++)
            {
                result.value[i][j]=(value[i][j]-b.value[i][j]);
            }
        }
        return result;
    }else{
    cout<<"Matrix dimensions are not correct.";

    }

}

void matrix::operator-=(matrix &b){
if(rows==b.rows&&columns==b.columns)
    {
        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=columns; j++)
            {
                value[i][j]=(value[i][j]-b.value[i][j]);
            }
        }
    }else{
    cout<<"Matrix dimensions are not correct.";

    }
}
