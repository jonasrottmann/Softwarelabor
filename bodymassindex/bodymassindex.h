//
//  bodymassindex.h
//  softwarelabor_c
//
//  Created by Jonas Rottmann on 26.03.14.
//  Copyright (c) 2014 Jonas Rottmann. All rights reserved.
//

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
