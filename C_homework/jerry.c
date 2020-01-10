#include <stdlib.h>
#include <stdio.h>
//#include <iostream>

//using namespace std;

int main()
{
    int y = 0, k = 0, zero = 0, len = 0, flag = 0, n, pos = 0, length, i, j;

    scanf("%d", &n);
    getchar();

    char array_list[12];
    int mul1[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
    int mul2[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};

    char c;

    for(i = 1; i <= n; i++){
    flag = 0;
    c = getchar();
    while(c != '\n'){
        array_list[pos] = c;
        //cout << "array_list[" << pos << "] =" << array_list[pos] << "\n";
        length = pos + 1;  //比实际长度小一
        pos++;
        c = getchar();
    }

    //cout << "length_ == " << length <<endl;

    pos = 0;

        if (array_list[0] == '-'){
            for (j = length - 1; j > 0; --j){
                if (array_list[j] != '0') flag = 1;
                if (flag == 1)  len++;
            }
            flag = 0;
            length = len+1;
            len = 0;
            //cout << "length = " << length<<endl;
        }
        else {
            for (j = length - 1; j >= 0; --j){
                if (array_list[j] != '0') flag = 1;
                if (flag == 1)  len++;
            }
            flag = 0;
            length = len;
            len = 0;
            //printf("%d\n", length);
        }

    //负数
        /*if (array_list[0] == '-'){ //负数
            if (length > 11) printf("%d\n", zero);
            else {
                for (j = 1; j < length; j++){
                    y = (int)(array_list[j] - 48);
                    //cout << "array_list[" << i << "][" << j <<"] = " << y << '\t';
                    for(m = 0; m <k; m++){
                        y *= 10;
                    }
                    x -= y;
                    //cout << "x = " << x <<endl;
                    k++;
                }
                //cout <<endl;
                //cout << "x = " << x<<endl;
                if (x > 0) printf("%d\n", zero);
                else printf("%d\n", x);
            }
            x = 0;
            k = 0;
        }

        else {      //正数
            if (length > 10) printf("%d\n", zero);
            else {
                for (j = 0; j < length; j++){
                    y = (int)(array_list[j] - 48);
                    //cout << "array_list[" << i << "][" << j <<"] = " << y << '\t';
                    for(m = 0; m <k; m++){
                        y *= 10;
                    }
                    x += y;
                    //cout << "x = " << x <<endl;
                    k++;
                }
                //cout <<endl;
                //cout << "x = " << x<<endl;
                if (x < 0) printf("%d\n", zero);
                else printf("%d\n", x);
            }
            x = 0;
            k = 0;
        }//*/
        if (array_list[0] == '-'){ //负数
            if (length > 11) printf("%d\n", zero);
            else if (length <= 10) {
                for (j = length - 1; j >= 1; --j){
                    y = (int)(array_list[j] - 48);
                    if(j != length - 1) printf("%d", y);
                    else {y = -y;  printf("%d", y);}
                }
                printf("\n");
                }
                else {
                    for (j = length - 1; j >= 1; --j){
                        y = (int)(array_list[j] - 48);
                        //cout << "array_list[" << i << "][" << j <<"] = " << y << '\t';
                        if (y > mul1[k]) {flag = 1; printf("%d\n", zero); break;}
                        //cout << "x = " << x <<endl;
                        k++;
                    }
                    if (flag != 1){
                        for (j = length - 1; j >= 1; --j){
                            y = (int)(array_list[j] - 48);
                            if(j != length - 1) printf("%d", y);
                            else {y = -y;  printf("%d", y);}
                        }
                        printf("\n");
                    }
                    flag = 0;
                    k = 0;
                }
        }

        else {      //正数
            if (length > 10) printf("%d\n", zero);
            else if (length <= 9) {
                for (j = length - 1; j >= 0; --j){
                    y = (int)(array_list[j] - 48);
                    printf("%d", y);
                }
                printf("\n");
                }
                else {
                    for (j = length - 1; j >= 0; --j){
                        y = (int)(array_list[j] - 48);
                        //cout << "array_list[" << i << "][" << j <<"] = " << y << '\t';
                        if (y > mul2[k]) {flag = 1; printf("%d\n", zero); break;}
                        //cout << "x = " << x <<endl;
                        k++;
                    }
                    if (flag != 1){
                        for (j = length - 1; j >= 0; --j){
                        y = (int)(array_list[j] - 48);
                        printf("%d", y);
                        }
                        printf("\n");
                    }
                    flag = 0;
                    k = 0;
                }
        }
    }//*/

    return 0;
}

