#ifndef __numero_h__
#define __numero_h__

/*****
Classe di test
 */
class numero
{
public:
    numero(const double n);
    //~numero();
    double getValore() { return _valore; }
    void setValore(double n) { _valore = n; }

private:
    double _valore;
};

#endif