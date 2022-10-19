#include <gtest/gtest.h>
#include "../src/cookie.h"

TEST(COOKIE,test1_even_1){
    int arr[]={1,2,3,4};
    double output = max_dv(sizeof(arr)/sizeof(arr[0]),arr);
    ASSERT_NEAR(output,6,0.01);
}

TEST(COOKIE,test2_even_2){
    int arr[]={2,6,3,4,3,5};
    double output = max_dv(sizeof(arr)/sizeof(arr[0]),arr);
    ASSERT_NEAR(output,15,0.01);
}

TEST(COOKIE,test3_odd_1){
    int arr[]={10,1,1,9,5,3};
    double output = max_dv(sizeof(arr)/sizeof(arr[0]),arr);
    ASSERT_NEAR(output,16,0.01);
}

TEST(COOKIE,test4_odd_2){
    int arr[]={10,9,10,9,5,3};
    double output = max_dv(sizeof(arr)/sizeof(arr[0]),arr);
    ASSERT_NEAR(output,25,0.01);
}

TEST(COOKIE,test5_dv_negative_1){
    int arr[]={10,9,-10,9,5,3};
    double output = max_dv(sizeof(arr)/sizeof(arr[0]),arr);
    ASSERT_NEAR(output,-1,0.01);
}

TEST(COOKIE,test6_dv_negative_2){
    int arr[]={10,9,10,9,5,-3};
    double output = max_dv(sizeof(arr)/sizeof(arr[0]),arr);
    ASSERT_NEAR(output,-1,0.01);
}

TEST(COOKIE,test7_n_negative_1){
    int arr[]={10,9,10,9,5,3};
    double output = max_dv(-10000,arr);
    ASSERT_NEAR(output,-1,0.01);
}

TEST(COOKIE,test8_n_negative_2){
    int arr[]={10,9,10,9,5,3};
    double output = max_dv(-2,arr);
    ASSERT_NEAR(output,-1,0.01);
}