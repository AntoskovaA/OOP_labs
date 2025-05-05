#ifndef LAB3_H
#define LAB3_H

class Dyhotomia
{
    private:
    double a, b, c, eps, end_root;

    public:
    Dyhotomia(){};
    ~Dyhotomia(){};
    void setData (double val_a, double val_b, double eps);
    void EndRoot();
    
    
    double showRoot ();
};


class NewtonsMethod {
    private:
    double Xn, next_X, tochnist;

    public:
    NewtonsMethod(){};
    ~NewtonsMethod(){};
    void setdata (double val_Xn, double val_toch);
    void Solution();
};


#endif