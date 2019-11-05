int main()
{
    int cantidad;
    int *x;

    printf("number of array's values");
    scanf("%d",&cantidad);

    x = (int*)malloc(sizeof(int));

    for(int i=0;i<cantidad;i++)
    {
        printf("data(int): ");
        scanf("%d",&x[i]);
    }

    //Visualizar Datos
    for(int i=0;i<cantidad;i++)
    {
        printf(" %d",x[i]);
    }

    return 0;
}
