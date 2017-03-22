//
//  main.cpp
//  HW4Test
//
//  Created by Harshit Pareek on 2/27/17.
//  Copyright © 2017 CS2134. All rights reserved.
//





//#include <iostream>
//
//using namespace std;
//
//int fib(int);
//
//int main()
//{
//    int num;
//    cout<<"Enter a positive number"<<endl;
//    cin >> num;
//    cout<<"the fibonacci value for "<<num <<" is: "<<fib(num)<<endl;
//    return 0;
//}
//int fib(int num)
//{
//    int f1 = 1;
//    int f2 = 1;
//    int f = 0;
//    for(int i=2;i<num;i++)
//    {
//        f = f1+f2;
//        f1 = f2;
//        f2 = f;
//    }
//    return f;
//}

//#include <iostream>
//
//using namespace std;
//double eApprox(int);
//
//int main()
//{
//    cout.precision(30);
//    for(int i=1;i<=15;i++)
//    {
//        cout<<"the value of e for "<<i<<" addend is: \n"<<eApprox(i)<<endl;
//    }
//    return 0;
//}
//double eApprox(int num)
//{
//    double sum = 0;
//    double multi = 1;
//    for(int i=0;i<=num;i++)
//    {
//        if(i == 0)
//        {
//            sum += 1;
//        }
//        else
//        {
//            multi *= i;
//            sum += 1/multi;
//        }
//    }
//    return sum;
//}
//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//void analyzeDividors(int, int&, int&);
//bool isPerfect(int);
//void allPerfectAndAmicable(int);
//
//int main()
//{
//    int num;
////    int outCountDivs = 0, outSumDivs = 0;
//    cout<<"Enter a number >=2"<<endl;
//    cin >> num;
//    allPerfectAndAmicable(num);
////    if(isPerfect(num))
////    {
////        cout<<"the number is perfect"<<endl;
////    }
////    else
////    {
////        cout<<"the number is not perfect"<<endl;
////    }
////    analyzeDividors(num, outCountDivs, outSumDivs);
////    cout<<"the value of outCountDivs is:"<<outCountDivs<<endl;
////    cout<<"the value of outSumDivs is:" << outSumDivs << endl;
//    return 0;
//}
//void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
//{
//    for(int i=1;i<=sqrt(num);i++)
//    {
//        if(num%i == 0)
//        {
//            // only taking the proper divisor except the number
//            if(num/i == i || i == 1)
//            {
//                outSumDivs += i;
//                outCountDivs++;
//            }
//            else
//            {
//                outSumDivs += i;
//                outSumDivs += num/i;
//                outCountDivs += 2;
//            }
//        }
//    }
//}
//bool isPerfect(int num)
//{
//    int count = 0;
//    int sum = 0;
//    analyzeDividors(num, count, sum);
//    if(sum == num)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//void allPerfectAndAmicable(int num)
//{
//    int sum = 0;
//    int count = 0;
//    for(int i=2;i<=num;i++)
//    {
//        sum = 0;
//        analyzeDividors(i, count, sum);
//        if(i == sum)
//        {
//            cout<<i<<" th number is perfect"<<endl;
//        }
//        else
//        {
//            int sum1 = 0;
//            int temp;
//            analyzeDividors(sum, count, sum1);
//            if(sum1 == i && temp != i)
//            {
//                cout<<i<<"  and  "<<sum<<" are amicable number"<<endl;
//                temp = sum;
//            }
//        }
//    }
//}
