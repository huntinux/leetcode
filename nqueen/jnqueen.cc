#include <iostream>
#include <cstdlib>
#include <cstring>

class NQueen
{
    static const int kMaxQueen = 16;

 public:
    NQueen(int n) : N(n), count(0)
    {
        bzero(column, sizeof column);
        bzero(diagnoal, sizeof diagnoal);
        bzero(antidiagnoal, sizeof antidiagnoal);
    }

    void search(const int row)
    {
        //std::cout << "search row " << row << std::endl;
        for(int i = 0; i < N; i++)
        {
            int d = row - i + N;
            //std::cout << "row: " << row  << std::endl;
            //std::cout << "column: " << i << std::endl;
            //std::cout << "diagnoal : " << d << std::endl;
            //std::cout << "antidiagnoal : " << row+i << std::endl;
            if(!(column[i] || diagnoal[d] || antidiagnoal[row+i])) {
                if(row == N-1) {
                    count++;
                }else{
                    column[i] = true;
                    diagnoal[d] = true;
                    antidiagnoal[row+i] = true;
                    search(row + 1);
                    column[i] = false;
                    diagnoal[d] = false;
                    antidiagnoal[row+i] = false;
                }
            }
        }
    }

    int result() const
    {
        return count;
    }

 private:
    // no copy
    NQueen(const NQueen&);
    NQueen& operator=(const NQueen&);

 private:
    int N;
    int count;
    bool column[kMaxQueen];
    bool diagnoal[2*kMaxQueen];
    bool antidiagnoal[2*kMaxQueen];
};

int main()
{
    NQueen q(14);

    q.search(0);

    std::cout << q.result() << std::endl;

    return 0;
}
