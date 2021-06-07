#include "stdio.h"
#include "unistd.h"
#include "getopt.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"


extern double f1(double);
extern double f2(double);
extern double f3(double);
extern double proiz1(double);
extern double proiz2(double);
extern double proiz3(double);

double root(char * f, char * g, double a, double b, double eps1, double p_f(double), double p_g(double));
double integral(char * f, double a, double b, double eps2);
int count; //счетчик итераций при нахождении корня уравнения

int main(int argc, char *argv[]){


    double x1,x2,x3, S1,S2,S3,eps1=0.001,eps2=0.001;
    int Count=0;

//находим абсциссы точек пересечения
x3=root("f1", "f2", 1.0, 6.0, eps1, proiz1, proiz2);
Count+=count;
x2=root("f2", "f3", 1.0, 6.0, eps1, proiz2, proiz3);
Count+=count;
x1=root("f1", "f3", 1.0, 6.0, eps1, proiz1, proiz3);
Count+=count;//подсчитали общее количество итераций для всех функций


//находим интегралы функций
S1=integral("f1", x1, x3, eps2);
S2=integral("f2", x2, x3, eps2);
S3=integral("f3", x1, x2, eps2);
S1=S1-S2-S3;
printf("Площадь, ограниченная функциями: %lf\n", S1);

static struct option long_opt[] = {
                    {"help", no_argument, NULL, 'h'},
                    {"a", no_argument, NULL, 'a'},
                    {"c", no_argument, NULL, 'c'},
                    {"r",1,0,'r'},
                    {"i",1,0,'i'},
                    {0,0,0,0}
                  };
    int optIdx;

    int c;
    int n, i;
    double a, b, s1,s2,s, h, Eps2;
    double r, xi, pr, xii, Eps1;
    while (1){
    c = getopt_long(argc, argv, "r:i:helpac", long_opt, &optIdx);

    if(c == -1) return 0;
        switch( c ){
         case 'h':
             printf("-a(Абсциссы)\n-c(Количество итераций)\n-r(root): (№ функции(int), № функции(int), число а(double), число b(double), eps(double))\n-i(integral): (Число a(double), Число b(double), eps(double), № функции(int))\n");
             break;

         case 'a':
             printf("Абсциссы точек пересечения: %lf, %lf, %lf\n", x1, x2, x3);
             break;
         case 'c':
             printf("Количество итераций: %d\n", Count);
             break;
         case 'i':
             //тестирование функции integral
            n=10, i;
            a=atof(argv[optind-1]);
            b=atof(argv[optind]);
            Eps2=atof(argv[optind+1]);
            s1=0;
            s2=0;
            s=0;
            h=(b-a)/n;

            if(argv[optind+2][0]=='1'){
                for(i=0;i<n;i++){
                    s+=f1(a+i*h)+f1(a+(i+1)*h);
                }
                s1=(h*s)/2;
                n*=2;
                s=0;
                h=(b-a)/n;
                for(i=0;i<n;i++){
                    s+=f1(a+i*h)+f1(a+(i+1)*h);
                }
                s2=(h*s)/2;
                while(fabs(s1-s2)>=Eps2){
                    s1=s2;
                    n*=2;
                    s=0;
                    h=(b-a)/n;
                    for(i=0;i<n;i++){
                        s+=f1(a+i*h)+f1(a+(i+1)*h);
                    }
                    s2=(h*s)/2;
                }
                printf("Интеграл первой функции %lf\n", s2);
            }

            if(argv[optind+2][0]=='2'){

                for(i=0;i<n;i++){
                    s+=f2(a+i*h)+f2(a+(i+1)*h);
                }
                s1=(h*s)/2;

                n*=2;
                s=0;
                h=(b-a)/n;
                for(i=0;i<n;i++){
                    s+=f2(a+i*h)+f2(a+(i+1)*h);
                }
                s2=(h*s)/2;
                while(fabs(s1-s2)>=Eps2){
                    s1=s2;
                    n*=2;
                    s=0;
                    h=(b-a)/n;
                    for(i=0;i<n;i++){
                        s+=f2(a+i*h)+f2(a+(i+1)*h);
                    }
                    s2=(h*s)/2;
                }
                printf("Интеграл второй функции %lf\n", s2);
                }

            if(argv[optind+2][0]=='3'){
                    for(i=0;i<n;i++){
                        s+=f3(a+i*h)+f3(a+(i+1)*h);
                    }
                    s1=(h*s)/2;

                    n*=2;
                    s=0;
                    h=(b-a)/n;
                    for(i=0;i<n;i++){
                        s+=f3(a+i*h)+f3(a+(i+1)*h);
                    }
                    s2=(h*s)/2;
                    while(fabs(s1-s2)>=Eps2){
                        s1=s2;
                        n*=2;
                        s=0;
                        h=(b-a)/n;
                        for(i=0;i<n;i++){
                            s+=f3(a+i*h)+f3(a+(i+1)*h);
                        }
                        s2=(h*s)/2;
                    }
                    printf("Интеграл третьей функции %lf\n", s2);
                }


             break;
         case 'r':
                //тестирование функции root

                xi=atof(argv[optind+1]);
                Eps1=atof(argv[optind+3]);
             if(argv[optind-1][0]=='1' && argv[optind][0]=='2'){
                r=f1(xi);

                r=r-f2(xi);
                pr=proiz1(xi);
                pr=pr-proiz2(xi);
                xii=xi-(r/pr);


                while(fabs(xi-xii)>=Eps1){
                    count++;
                    xi=xii;
                    r=f1(xi);
                    r=r-f2(xi);
                    pr=proiz1(xi);
                    pr=pr-proiz2(xi);
                    xii=xi-(r/pr);

                }
                printf("Абсцисса точки пересечения f1 и f2 %lf\n", xii);


            }


    if(argv[optind-1][0]=='1' && argv[optind][0]=='3'){
        r=f1(xi);

        r=r-f3(xi);
        pr=proiz1(xi);
        pr=pr-proiz3(xi);
        xii=xi-(r/pr);


        while(fabs(xi-xii)>=Eps1){
            count++;
            xi=xii;
            r=f1(xi);
            r=r-f3(xi);
            pr=proiz1(xi);
            pr=pr-proiz3(xi);
            xii=xi-(r/pr);

        }

        printf("Абсцисса точки пересечения f1 и f3 %lf\n", xii);

    }

    if(argv[optind-1][0]=='2' && argv[optind][0]=='3'){
        r=f2(xi);

        r=r-f3(xi);
        pr=proiz2(xi);
        pr=pr-proiz3(xi);
        xii=xi-(r/pr);


        while(fabs(xi-xii)>=Eps1){
            count++;
            xi=xii;
            r=f2(xi);
            r=r-f3(xi);
            pr=proiz2(xi);
            pr=pr-proiz3(xi);
            xii=xi-(r/pr);

        }

        printf("Абсцисса точки пересечения f2 и f3 %lf\n", xii);
    }

        break;
    }



    }
    return 0;
}


double root(char * f, char * g, double a, double b, double eps1, double p_f(double), double p_g(double)){
    double r, xi=a, pr, xii;

    count=0;
    if(f[1]=='1' && g[1]=='2'){
        r=f1(xi);

        r=r-f2(xi);
        pr=p_f(xi);
        pr=pr-p_g(xi);
        xii=xi-(r/pr);



        while(fabs(xi-xii)>=eps1){
            count++;
            xi=xii;
            r=f1(xi);
            r=r-f2(xi);
            pr=p_f(xi);
            pr=pr-p_g(xi);
            xii=xi-(r/pr);

        }

        return xii;

    }
    if(f[1]=='2' && g[1]=='1'){
         r=f1(xi);

        r=r-f2(xi);
        pr=p_g(xi);
        pr=pr-p_f(xi);
        xii=xi-(r/pr);



        while(fabs(xi-xii)>=eps1){
            count++;
            xi=xii;
            r=f1(xi);
            r=r-f2(xi);
            pr=p_g(xi);
            pr=pr-p_f(xi);
            xii=xi-(r/pr);

        }

        return xii;

    }
    if(f[1]=='1' && g[1]=='3'){
        r=f1(xi);

        r=r-f3(xi);
        pr=p_f(xi);
        pr=pr-p_g(xi);
        xii=xi-(r/pr);


        while(fabs(xi-xii)>=eps1){
            count++;
            xi=xii;
            r=f1(xi);
            r=r-f3(xi);
            pr=p_f(xi);
            pr=pr-p_g(xi);
            xii=xi-(r/pr);

        }

        return xii;

    }
    if(f[1]=='3' && g[1]=='1'){
        r=f1(xi);

        r=r-f3(xi);
        pr=p_g(xi);
        pr=pr-p_f(xi);
        xii=xi-(r/pr);



        while(fabs(xi-xii)>=eps1){
            count++;
            xi=xii;
            r=f1(xi);
            r=r-f3(xi);
            pr=p_g(xi);
            pr=pr-p_f(xi);
            xii=xi-(r/pr);

        }

        return xii;
    }
    if(f[1]=='2' && g[1]=='3'){
        r=f2(xi);

        r=r-f3(xi);
        pr=p_f(xi);
        pr=pr-p_g(xi);
        xii=xi-(r/pr);



        while(fabs(xi-xii)>=eps1){
            count++;
            xi=xii;
            r=f2(xi);
            r=r-f3(xi);
            pr=p_f(xi);
            pr=pr-p_g(xi);
            xii=xi-(r/pr);

        }

        return xii;
    }
    if(f[1]=='3' && g[1]=='2'){
        r=f2(xi);

        r=r-f3(xi);
        pr=p_g(xi);
        pr=pr-p_f(xi);
        xii=xi-(r/pr);



        while(fabs(xi-xii)>=eps1){
            count++;
            xi=xii;
            r=f2(xi);
            r=r-f3(xi);
            pr=p_g(xi);
            pr=pr-p_f(xi);
            xii=xi-(r/pr);

        }

        return xii;
    }
    return 0.0;
}

double integral(char * f, double a, double b, double eps2){
    int n=10, i;

    double s1=0, s2=0, s=0, h;
    h=(b-a)/n;
    if(f[1]=='1'){
        for(i=0;i<n;i++){
            s+=f1(a+i*h)+f1(a+(i+1)*h);
        }
        s1=(h*s)/2;

        n*=2;
        s=0;
        h=(b-a)/n;
        for(i=0;i<n;i++){
            s+=f1(a+i*h)+f1(a+(i+1)*h);
        }
        s2=(h*s)/2;
        while(fabs(s1-s2)>=eps2){
            s1=s2;
            n*=2;
            s=0;
            h=(b-a)/n;
            for(i=0;i<n;i++){
                s+=f1(a+i*h)+f1(a+(i+1)*h);
            }
            s2=(h*s)/2;
        }
        return s2;
    }
    if(f[1]=='2'){

        for(i=0;i<n;i++){
            s+=f2(a+i*h)+f2(a+(i+1)*h);
        }
        s1=(h*s)/2;

        n*=2;
        s=0;
        h=(b-a)/n;
        for(i=0;i<n;i++){
            s+=f2(a+i*h)+f2(a+(i+1)*h);
        }
        s2=(h*s)/2;
        while(fabs(s1-s2)>=eps2){
            s1=s2;
            n*=2;
            s=0;
            h=(b-a)/n;
            for(i=0;i<n;i++){
                s+=f2(a+i*h)+f2(a+(i+1)*h);
            }
            s2=(h*s)/2;
        }
        return s2;


    }
    if(f[1]=='3'){
        for(i=0;i<n;i++){
            s+=f3(a+i*h)+f3(a+(i+1)*h);
        }
        s1=(h*s)/2;

        n*=2;
        s=0;
        h=(b-a)/n;
        for(i=0;i<n;i++){
            s+=f3(a+i*h)+f3(a+(i+1)*h);
        }
        s2=(h*s)/2;
        while(fabs(s1-s2)>=eps2){
            s1=s2;
            n*=2;
            s=0;
            h=(b-a)/n;
            for(i=0;i<n;i++){
                s+=f3(a+i*h)+f3(a+(i+1)*h);
            }
            s2=(h*s)/2;
        }
        return s2;
    }

        return 0.0;
}
