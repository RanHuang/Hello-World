/*
 *牛人用C语言写简历: http://mobile.51cto.com/comment-468867.htm
 *
 */
#include <stdio.h> 
#include <time.h> 
   
typedef struct { 
    union { 
        const char * company; 
        const char * school; 
        const char * project; 
    }; 
    union { 
        const char * location; 
        const char * url; 
    }; 
    union { 
        const char * title; 
        const char * program; 
    }; 
   
    time_t started; 
    time_t left; 
   
    const char * description[]; 
} thing_t; 
   
typedef thing_t job_t; 
typedef thing_t school_t; 
typedef thing_t project_t; 
   
#define CURRENT 0 /* I wasn't alive at the Unix epoch, so that'll work */ 
   
/* Contact Information */ 
const char * name    = "Kevin R. Lange"; 
const char * email   = "klange@toaruos.org"; 
const char * address = "1045 Mission St, Apt 440\n" 
                       "San Francisco, CA 94103"; 
   
/* Education */ 
school_t uiuc = { 
    .school   = "University of Illinois at Urbana-Champaign", 
    .location = "Urbana, IL", 
    .program  = "BS Computer Science", 
    .started  = 1251158400, 
    .left     = 1336608000, 
    .description = { 
        "Minor in International Studies in Engineering, Japan", 
        "Focused on systems software courses", 
        NULL 
    } 
}; 
   
school_t hit = { 
    .school   = "Hiroshima Institute of Technology", 
    .location = "Hiroshima, Japan", 
    .program  = "Study Abroad", 
    .started  = 1274745600, 
    .left     = 1278288000, 
    .description = { 
        "Cultural exchange program", 
        "Intensive language course", 
        NULL 
    } 
}; 
   
school_t * schools[] = { 
    &uiuc, 
    &hit, 
    NULL 
}; 
   
/* Projects */ 
project_t compiz = { 
    .project = "Compiz Window Manager", 
    .url     = "http://compiz.org", 
    .title   = "Developer", 
    .started = 1201392000, 
    .left    = 1264291200, 
    .description = { 
        "Minor plugin contributor", 
        "Various research projects", 
        NULL 
    } 
}; 
   
project_t toaruos = { 
    .project = "ToAruOS", 
    .url     = "https://github.com/klange/toaruos", 
    .title   = "Lead", 
    .started = 1295049600, 
    .left    = CURRENT, 
    .description = { 
        "Hobby x86 Unix-like kernel and userspace", 
        "Advanced in-house GUI with compositing window manager", 
        NULL 
    } 
}; 
   
project_t * projects[] = { 
    &toaruos, 
    &compiz, 
    NULL 
}; 
   
/* Employment History */ 
   
job_t yelp = { 
    .company  = "Yelp, Inc.", 
    .location = "San Francisco, CA", 
    .title    = "Software Engineer, i18n", 
    .started  = 1339977600, 
    .left     = CURRENT, 
    .description = { 
        "Developed several internal tools and libraries", 
        "Provided critical input and design work for Yelp's launch in Japan", 
        NULL 
    } 
}; 
   
job_t apple_internship = { 
    .company  = "Apple Inc.", 
    .location = "Cupertino, CA", 
    .title    = "Software Engineering Intern", 
    .started  = 1306886400, 
    .left     = 1314662400, 
    .description = { 
        "Built software framework for testing and verification of desktop retina display modes", 
        "Assisted other interns with Unix fundamentals", 
        NULL 
    } 
}; 
   
job_t * jobs[] = { 
    &yelp, 
    &apple_internship, 
    NULL 
}; 
   
void print_thing(thing_t * thing) { 
    char started[100]; 
    char left[100]; 
    struct tm * ti; 
   
    printf("%s at %s - %s\n", thing->title, thing->company, thing->location); 
   
    ti = localtime(&thing->started); 
    strftime(started, sizeof(started), "%B %d, %Y", ti); 
   
    if (thing->left == CURRENT)  { 
        printf("%s to now\n", started); 
    } else { 
        ti = localtime(&thing->left); 
        strftime(left, sizeof(left), "%B %d, %Y", ti); 
        printf("%s to %s\n", started, left); 
    } 
   
    const char ** desc; 
    for (desc = thing->description; *desc; desc++) { 
        printf("- %s\n", *desc); 
    } 
   
    puts(""); 
} 
   
int main(int argc, char ** argv) { 
   
    school_t ** s; 
    job_t ** j; 
    project_t ** p; 
   
    printf("%s\n%s\n%s\n\n", name, email, address); 
   
    puts("Education\n"); 
    for (s = schools; *s; s++) { 
        print_thing(*s); 
    } 
   
    puts("Employment\n"); 
    for (j = jobs; *j; j++) { 
        print_thing(*j); 
    } 
   
    puts("Projects\n"); 
    for (p = projects; *p; p++) { 
        print_thing(*p); 
    } 
   
    return 0; 
}
