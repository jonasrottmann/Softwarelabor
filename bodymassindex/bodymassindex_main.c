//
//  bodymassindex_main.c
//  softwarelabor_c
//
//  Created by Jonas Rottmann on 26.03.14.
//  Copyright (c) 2014 Jonas Rottmann. All rights reserved.
//

#include <stdio.h>
#include "bodymassindex_view.h"
#include "bodymassindex.h"

int main(void) {
    struct Bodymassindex body;
    
    gewicht_eingeben(&body);
    groesse_eingeben(&body);
    
    body_mass_index_anzeigen(body);
    
    return 0;
}
