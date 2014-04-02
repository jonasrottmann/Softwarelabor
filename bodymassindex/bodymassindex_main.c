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
