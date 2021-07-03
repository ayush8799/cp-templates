




// #include<stdio.h>
// //Position this line where user code will be pasted.



// void printNos(int n)
// {
//     if (n > 0)
//     {
//         printNos(n - 1);
//         printf("%d ",  n);
//     }
// }

// void printTillN(int N)
// {
//     printNos(N);
//     printf("\n");
// }




// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif
//     int t;
//     scanf("%d", &t);
//     while (t--)
//     {
//         int N;
//         scanf("%d", &N);
//         printTillN(N);

//     }
//     return 0;
// }






























































































#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    /* Prints numbers from 1 to n */
    void printNos(int n)
    {
        if (n > 0)
        {
            printNos(n - 1);
            cout << n << " ";
        }
        return;
    }
    void printTillN(int N)
    {
        printNos(N);
        cout << endl;
    }
};


//Position this line where user code will be pasted.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        ob.printTillN(N);

    }
    return 0;
}
















































































































// // { Driver Code Starts
// //Initial Template for C++

// #include <iostream>
// using namespace std;



// // } Driver Code Ends
// //User function Template for C++

// void volume(int s)
// {
//     cout << (s * s * s) << endl;
// }

// void volume(int r, int h)
// {
//     cout << (3.14159 * r * r * h) << endl;
// }

// void volume(int l, int b, int h)
// {
//     cout << (l * b * h) << endl;
// }

// // { Driver Code Starts.
// int main()
// {

// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int q;
//         cin >> q;

//         switch (q)
//         {
//         case 1:
//             int edge;
//             cin >> edge;
//             volume(edge);
//             break;

//         case 2:
//             int radius, heigh;
//             cin >> radius >> heigh;
//             volume(radius, heigh);
//             break;

//         case 3:
//             int length, width, height;
//             cin >> length >> width >> height;
//             volume(length, width, height);
//             break;

//         }

//         char tilde;
//         cin >> tilde;
//         cout << tilde << endl;

//     }

//     return 0;
// }  // } Driver Code Ends