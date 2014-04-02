#ifndef softwarelabor_c_bodymassindex_h
#define softwarelabor_c_bodymassindex_h

enum Gewichtsklasse {UNTERGEWICHT = 0, NORMALGEWICHT, ADIPOSITAS};

struct Bodymassindex {
    double gewicht;
    double groesse;
};

enum Gewichtsklasse get_gewichtsklasse(struct Bodymassindex);

double berechne_body_mass_index(struct Bodymassindex);


#endif
