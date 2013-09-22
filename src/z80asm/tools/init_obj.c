/* generated by {{ prog }} {{ args.join(' ') }} */

/* includes */
#include "memalloc.h"   			/* before any other include */

#include "init.h"
#include <stdlib.h>
#include <stdio.h>

/* data types */
typedef struct ObjectRegister_store
{
	void (*delete_func)(void **);	/* delete function pointer, NULL if no auto-delete */
} ObjectRegister_store;

/* global data */
GSList *object_register;			/* all registered objects for cleanup at end */

/* declare functions */
static void object_register_init(void);
static void object_register_fini(void);
static ObjectRegister_store *first_autodelete(void);

/* register atexit(), die on error */
void xatexit(void (*fini)(void))
{
	if (atexit(fini))
	{
		fprintf(stderr, "atexit() failed\n");
		exit(1);
	}
}

/* get first object in register with autodelete set */
static ObjectRegister_store *first_autodelete(void)
{
	GSList *object;
	ObjectRegister_store *data;
	
	for ( object = object_register; 
		  object; 
		  object = g_slist_next( object ) )
	{
		data = (ObjectRegister_store *) object->data;
		if ( data->delete_func )
			return data;
	}
	return NULL;		
}

/* initialize object register */
static void object_register_init(void)
{
	static BOOL initialized = FALSE;

	if ( ! initialized )
	{
		xatexit( object_register_fini );
		initialized = TRUE;
	}
}

/* cleanup object register, release all memory */
static void object_register_fini(void)
{
	ObjectRegister_store *store;
	void                 *data;
	
	/* search list from start on each iteration, as list may be modified by object delete */
	while ( (store = first_autodelete()) != NULL )
	{
		data = OBJREG_DATA_ADDR(store);
		(store->delete_func)( &data );
	}
	g_slist_free( object_register );
	object_register = NULL;
}

/* register object */
extern void register_object ( void *object )
{
	object_register_init();
	object_register = g_slist_prepend( object_register, object );
}

/* unregister object */
extern void unregister_object ( void *object )
{
	object_register_init();
	object_register = g_slist_remove( object_register, object );
}

