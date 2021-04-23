

int main(int argc, char * argv[])
{
    int size = 7;
    int low = 0;
    int high = size - 1;

    printf("low=%d, high=%d\n", (low-1)%size, (high+1)%size);

    return 0;
}
