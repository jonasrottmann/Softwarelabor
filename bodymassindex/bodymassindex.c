//
//  bodymassindex.c
//  softwarelabor_c
//
//  Created by Jonas Rottmann on 26.03.14.
//  Copyright (c) 2014 Jonas Rottmann. All rights reserved.
//

#include <stdio.h>


#include "bodymassindex.h"

enum Gewichtsklasse get_gewichtsklasse(struct Bodymassindex body) {
    double body_mass_index = berechne_body_mass_index(body);
    if (body_mass_index <= 18.5) {
        return UNTERGEWICHT;
    } else if (body_mass_index >= 25.0) {
        return ADIPOSITAS;
    } else {
        return NORMALGEWICHT;
    }
}

double berechne_body_mass_index(struct Bodymassindex body) {
    return body.gewicht / (body.groesse * body.groesse);
}



