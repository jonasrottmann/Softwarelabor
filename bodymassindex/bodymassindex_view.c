//
//  bodymassindex_view.c
//  softwarelabor_c
//
//  Created by Jonas Rottmann on 26.03.14.
//  Copyright (c) 2014 Jonas Rottmann. All rights reserved.
//

#include <stdio.h>
#include "bodymassindex_view.h"

void body_mass_index_anzeigen(struct Bodymassindex body) {
    double body_mass_index;
    
    body_mass_index = berechne_body_mass_index(body);
    
    printf("Ihr Body-Mass-Index ist: %lf\n", body_mass_index);
    switch ( get_gewichtsklasse(body) ) {
        case NORMALGEWICHT: printf("(Normalgewicht)\n");
            break;
        case UNTERGEWICHT:  printf("(Untergewicht)\n");
            break;
        case ADIPOSITAS:    printf("(Adipositas)\n");
            break;
    }
}

void groesse_eingeben(struct Bodymassindex *body) {
    printf("Körpergrösse [m]: ");
    scanf("%lf", &body->groesse);
}

void gewicht_eingeben(struct Bodymassindex *body) {
    printf("Gewicht [kg]: ");
    scanf("%lf", &body->gewicht);
}