#include<stdio.h>

#include<deque>

using namespace std;

int n,m;

char frined[50][11];

//d : i번 음식을 먹을수 있는 친구 번호

//caneat : i번 친구가 먹을 수 있는 음식 번호

deque<int> d[50], caneat[50];

//이미 선택된 음식

bool cooked[50];

//문자열 비교

bool strcmp(char a[],char b[])

{

    //같으면 true

    int i;

    for(i=0;a[i]!='\0' && b[i]!='\0';i++)

    {

        if(a[i]!=b[i]) return false;

    }

    return a[i]==b[i];

}

//dish : i번 친구가 먹을 수 있는 음식 갯수

int dish[50], ans;

void worker(int chosen)

{

    //일명 가지치기

    if(chosen>=ans) return;

    //아직 먹을 음식이 없는 친구들 중에서 먹을 수 있는 음식의 갯수가 가장 적은 친구를 선정

    int tar_f=-1;

    for(int i=0;i<n;i++)

    {

        if(dish[i]==0 && (tar_f==-1 || caneat[i].size()<caneat[tar_f].size())) tar_f=i;

    }

    if(tar_f==-1)

    {

        //모든 친구들이 먹을 음식 선택 완료

        if(ans>chosen) ans=chosen;

        return;

    }

    // 선택된 친구가 먹을 수 있는 음식들을 가지고 Backtracking 구현

    for(int i=0;i<caneat[tar_f].size();i++)

    {

        if(!cooked[caneat[tar_f][i]])

        {

            cooked[caneat[tar_f][i]]=true;

            for(int j=0;j<d[caneat[tar_f][i]].size();j++) dish[d[caneat[tar_f][i]][j]]++;

            worker(chosen+1);

            for(int j=0;j<d[caneat[tar_f][i]].size();j++) dish[d[caneat[tar_f][i]][j]]--;

            cooked[caneat[tar_f][i]]=false;

        }

    }

}

int main()

{

    int r;

    scanf("%d",&r);

    while(r--)

    {

        scanf("%d%d",&n,&m);

        ans=51;

        for(int i=0;i<50;i++)

        {

            d[i].clear();

            caneat[i].clear();

        }

        for(int i=0;i<n;i++)

        {

            scanf("%s",frined[i]);

        }

        for(int i=0;i<m;i++)

        {

            int t;

            scanf("%d",&t);

            for(int j=0;j<t;j++)

            {

                char str[11];

                scanf("%s",str);

                for(int fc=0;fc<n;fc++)

                {

                    if(strcmp(str,frined[fc]))

                    {

                        d[i].push_back(fc);

                        caneat[fc].push_back(i);

                        break;

                    }

                }

            }

        }

        worker(0);

        printf("%d\n",ans);

    }

    return 0;


}
