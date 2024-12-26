#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *f;
void menu();
void input_order();
void total_order(int);
void order_summary(int,int);
void print_order_summary();
int order[7] = {150,80,60,90,50,20,150};
int main(){
    menu();
    return 0;
}
void menu()
{
    printf("\n");
    printf("\t\tD's Caffe\n");
    printf("1. Pizza - 150 Rs\n");
    printf("2. Pasta - 80 Rs\n");
    printf("3. Maggie - 60 Rs\n");
    printf("4. Momos - 90 Rs\n");
    printf("5. Coffee - 50 Rs\n");
    printf("6. Tea - 20 Rs\n");
    printf("7. Mixed(Maggie & Pasta) - 150 Rs\n");
    input_order();
}
void input_order()
{
    int total = 0;
    int wyw;
    while(1){
        printf("Enter Your Order(1-7): ");
        scanf("%d",&wyw);
        if(wyw <= 0 && wyw > 7){
            printf("Invalid Order Selection!!\n");
            printf("Please select as per the given Menu!!");
        }
        else{
            int quantity;
            printf("Enter Quantity: ");
            scanf("%d",&quantity);
            if(quantity == 0){
                printf("Sir dont make fun please 😂\n");
            }
            order_summary(wyw,quantity);
            total += quantity*order[wyw - 1];
            wyw = 0;
        }
        char ch;
        printf("Do You want anything more(y/n): ");
        scanf(" %c",&ch);
        if(ch == 'n'){
           total_order(total);
           break;
        }
    }   
}
void total_order(int total){
    printf("Thank You for coming sir have a good day!!\n");
    printf("Sir Your Bill: %d",total);
    print_order_summary();
}
void order_summary(int o,int q){
    char text[1024];
    f = fopen("order.txt","a");
    switch (o)
    {
    case 1:
        fprintf(f,"Pizza Qty: %d - %d\n",q,q*order[0]);
        break;
    case 2:
        fprintf(f,"Pasta Qty: %d - %d\n",q,q*order[1]);
        break;
    case 3:
        fprintf(f,"Maggie Qty: %d - %d\n",q,q*order[2]);
        break;
    case 4:
        fprintf(f,"Momos Qty: %d - %d\n",q,q*order[3]);
        break;
    case 5:
        fprintf(f,"Coffee Qty: %d - %d\n",q,q*order[4]);
        break;
    case 6:
        fprintf(f,"Tea Qty: %d - %d\n",q,q*order[5]);
        break;
    case 7:
        fprintf(f,"Mixed(Maggie & Pasta) Qty: %d - %d\n",q,q*order[6]);
        break;
    default:
        break;
    }
}
void print_order_summary() {
    FILE *f = fopen("order.txt", "r");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[256]; // Buffer to hold each line of the file
    printf("\nOrder Summary:\n");
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line); // Print each line
    }

    fclose(f);
}