/**
 * Program to Count Inversions in an array
 * Compilation : gcc count_inversions.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 11/8/2021
 * Assignment 7 - Sorting .
 *
 */

#include<stdio.h>
#define ll long long int 

 ll  merge(ll a[], ll left, ll mid, ll right)
 {
    
    ll count_inversions =0;  //variable to count inversions
    if(right <= left)
	return 0 ;
    ll i = left;
    ll j = mid+1;
    ll k = left;
    ll b[right+2];
    while(i <= mid && j <= right)
    {
     //basic idea is if order is maintained we add it to our final array 
     if(a[i] <= a[j])
        {
         b[k] = a[i];
         ++i;
                 
        }
     //else order is broken now and we know how many inversions are going to happen 
     else
        {

         b[k] = a[j];
         ++j;
	count_inversions += mid - i + 1; 
        }

        ++k;
    }

    while(i <= mid)
    {
        b[k] = a[i];
        ++i;
        ++k;
             
    }
    while(j <= right)
    {
        b[k] = a[j];
        ++j;
        ++k;
    }
    for( i = left ; i <= right ; ++i)
        a[i] = b[i];

    return count_inversions ;//return total inversions
    }
ll mergeSort(ll a[], ll left, ll right)
{
    
    if(right <= left)
       return 0;
    ll mb =(left + right)/2;
    ll count_inversions = 0;
    //counting inversions while breaking array
    count_inversions += mergeSort(a,left , mb);
    count_inversions += mergeSort(a, mb+1 , right);
    count_inversions += merge(a, left , mb, right);
    return count_inversions; 
    
}


int main() {
    
   
    long long N;
    scanf("%lld", &N);
    long long A[N];
    for(long long i = 0 ; i < N ; i++)
    {
	    scanf("%lld", &A[i]);
	    
    }
    long long answer = mergeSort(A, 0, N-1);
    printf("%lld\n", answer );
    
    return 0;
}

