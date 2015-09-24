/*Matrix class*/

#include <math.h>


class Matx
{
    public:
      Matx(int rowg,int colg,double * mdag)
      {
          int ii=0;
          rown=rowg,coln=colg;
          mda=(double *)malloc(sizeof(double)*rown*coln);
          for (ii=0;ii<rown*coln;ii++)
            *(mda+ii)=*(mdag+ii);
      }
      Matx(int rowg,int colg)
      {
          rown=rowg,coln=colg;
          int ii;
          mda=(double *)malloc(sizeof(double)*rown*coln);
          for (ii=0;ii<rown*coln;ii++)
              *(mda+ii)=0;
      }

      int asstw(double * mdag)
      {
          int ii=0;
          for (ii=0;ii<rown*coln;ii++)
            *(mda+ii)=*(mdag+ii);
            return 1;
      }

      int assts(double gie,int ai)
      {
          *(mda+ai)=gie;
      }

      Matx add(Matx * Mxod)
      {
          Matx  reMx(rown,coln);
          int ii=0;
          for (ii=0;ii<rown*coln;ii++)
            *(reMx.mda+ii)=*(Mxod->mda+ii)+*(mda+ii);

        return  reMx;
      }

      Matx mins(Matx * Mxod)
      {
          Matx reMx(rown,coln);
          int ii=0;
          for (ii=0;ii<rown*coln;ii++)
            *(reMx.mda+ii)=*(Mxod->mda+ii)+*(mda+ii);

          return reMx;
      }

      Matx muly(Matx * Mxod)
      {
          int ii=0,ic=0;
          double elev=0;
          Matx reMx(rown,Mxod->gecl());
          if (coln!=Mxod->gerw())
          {
              std::cout<<"can't multiply"<<std::endl;
              exit(1);
          }
          for (ii=1;ii<=rown*Mxod->gecl();ii++) /*ii the number of element*/
          {
              /*row:ii/rown+1, col:ii%Mxod->gecl()*/
              /*res:(row-1)*coln+1,radd:1 ces:col,cadd:Mxod->coln*/
              elev=0;
              for (ic=0;ic<coln;ic++)
              elev+=(*(mda-1+(((ii-1)/rown)*coln+1+ic)))*(Mxod->geet((ii-1)%Mxod->gecl()+1+ic*(Mxod->gecl())-1));
              reMx.assts(elev,ii-1);
          }
          return reMx;
      }

      /*Matx inve(Matx * Mxod)
      {
          Matx reMx;
          Mxod
      }*/

      void shoe()
      {
          int ii=0;
          for (ii=0;ii<rown*coln;ii++)
          {
              std::cout<<*(mda+ii)<<" ";
              if ((ii+1)%coln==0)
                std::cout<<std::endl;
          }
      }

      /*double dett()
      {
          if (coln!=rown)
            return NULL;

      }*/

      //~Matx();

      int gerw()
      {
          return rown;
      }

      int gecl()
      {
          return coln;
      }

      double geet(int ii)
      {
          return *(mda+ii);
      }

        private:
        int rown=0,coln=0;
        double * mda;



};



