/*
    จากอาเรย์เดิม ที่มีค่าอยู่ก่อนแล้วคือ { 9, 2, 6, 1, 7 } จงเขียนโปรแกรมเพื่อรับค่าจากผู้ใช้อีก N จำนวน เพื่อนำไปต่อในอาเรย์เดิม และจัดเรียงใหม่จากน้อยไปยังมาก
    
    Test case:
        Enter new element of Array :
            4
        Input :
            3
        Input :
            4
        Input :
            2
        Input :
            5
    Output:
        Old Array: 9 2 6 1 7
        New Array: 1 2 2 3 4 4 5 6 7 9
*/

#include <stdio.h>

// ฟังก์ชันสำหรับผสานและเรียงอาเรย์
void mergeAndSort( int oldArray[], int oldSize, int newArray[], int newSize, int resultArray[] ) {
    int i = 0, j = 0, k = 0 ;

    // ผสานและเรียงอาเรย์ oldArray และ newArray
    while ( i < oldSize && j < newSize ) {
        if ( oldArray[i] < newArray[j] ) {
            resultArray[k++] = oldArray[i++] ;
        } else {
            resultArray[k++] = newArray[j++] ;
        }
    }

    // เมื่อผสานแล้วเราจะต้องตรวจสอบว่าอาเรย์ใดยังเหลือข้อมูลอยู่
    while ( i < oldSize ) {
        resultArray[k++] = oldArray[i++] ;
    }

    while ( j < newSize ) {
        resultArray[k++] = newArray[j++] ;
    }

    // เรียงลำดับผลลัพธ์ทั้งหมดจากน้อยไปมาก
    for ( i = 0 ; i < k - 1 ; i++ ) {
        for ( j = 0; j < k - i - 1; j++ ) {
            if ( resultArray[j] > resultArray[j + 1] ) {
                int temp = resultArray[j];
                resultArray[j] = resultArray[j + 1] ;
                resultArray[j + 1] = temp;
            }
        }
    }
}

int main() {
    int oldArray[] = {9, 2, 6, 1, 7} ;
    int N ;

    printf( "Enter new element of Array:\n" ) ;
    scanf( "%d" , &N ) ;

    int newArray[N] ;

    printf( "Input:\n" ) ;
    for ( int i = 0; i < N; i++ ) {
        scanf( "%d" , &newArray[i] ) ;
    }

    int newArraySize = N ;
    int resultArray[N + 5] ; // เราจะไม่มีอาเรย์ที่มีขนาดมากกว่า N + 5

    // เรียง oldArray จากน้อยไปมาก
    int oldArraySize = sizeof( oldArray ) / sizeof( oldArray[0] ) ;
    for ( int i = 0; i < oldArraySize - 1; i++ ) {
        for ( int j = 0; j < oldArraySize - i - 1; j++ ) {
            if ( oldArray[j] > oldArray[j + 1] ) {
                int temp = oldArray[j] ;
                oldArray[j] = oldArray[j + 1] ;
                oldArray[j + 1] = temp ;
            }
        }
    }

    // เรียกใช้ฟังก์ชันเพื่อผสานและเรียงอาเรย์
    mergeAndSort(oldArray, oldArraySize, newArray, newArraySize, resultArray) ;

    printf( "Old Array: {9, 2, 6, 1, 7} " ) ;
   

    printf( "\nNew Array:" ) ;
    for ( int i = 0; i < newArraySize + oldArraySize ; i++ ) {
        printf( " %d" , resultArray[i] ) ;
    }

    return 0 ;
}
