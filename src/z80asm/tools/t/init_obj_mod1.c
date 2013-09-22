/* generated by make_init.pl mod1.h mod2.h mod3.h */

/* includes */
#include "memalloc.h"   			/* before any other include */

#include "init.h"



/* data store for managed object */
typedef struct Person_store
{
	void (*delete_func)(Person **);	/* delete function pointer, NULL if no auto-delete */
	Person data;
} Person_store;

/* Person: create, destroy, set/clear autodelete */
Person * new_Person (  char * name,  int age )
{
	Person_store *self_store = g_slice_new0( Person_store );
	Person *self = (Person *) OBJREG_DATA_ADDR( self_store );
	
	autodelete_Person( self, TRUE );

	struct_Person_init( self, name, age );

	register_object( (void*) self_store );

	return self;
}

void delete0_Person ( Person **pself )
{
	if ( *pself )
	{
		Person_store *self_store = 
				(Person_store *) OBJREG_STORE_ADDR( *pself );
		
		unregister_object( (void*) self_store );

		struct_Person_fini( *pself );

		g_slice_free( Person_store, self_store );

		*pself = NULL;
	}
}

void delete_Person ( Person *self )
{
	delete0_Person( &self );
}

void autodelete_Person ( Person *self, BOOL autodelete )
{
	Person_store *self_store = 
			(Person_store *) OBJREG_STORE_ADDR( self );
	
	self_store->delete_func = autodelete ? delete0_Person : NULL;
}




/* data store for managed object */
typedef struct Person0_store
{
	void (*delete_func)(Person0 **);	/* delete function pointer, NULL if no auto-delete */
	Person0 data;
} Person0_store;

/* Person0: create, destroy, set/clear autodelete */
Person0 * new_Person0 ( void )
{
	Person0_store *self_store = g_slice_new0( Person0_store );
	Person0 *self = (Person0 *) OBJREG_DATA_ADDR( self_store );
	
	autodelete_Person0( self, TRUE );

	register_object( (void*) self_store );

	return self;
}

void delete0_Person0 ( Person0 **pself )
{
	if ( *pself )
	{
		Person0_store *self_store = 
				(Person0_store *) OBJREG_STORE_ADDR( *pself );
		
		unregister_object( (void*) self_store );

		g_slice_free( Person0_store, self_store );

		*pself = NULL;
	}
}

void delete_Person0 ( Person0 *self )
{
	delete0_Person0( &self );
}

void autodelete_Person0 ( Person0 *self, BOOL autodelete )
{
	Person0_store *self_store = 
			(Person0_store *) OBJREG_STORE_ADDR( self );
	
	self_store->delete_func = autodelete ? delete0_Person0 : NULL;
}




/* data store for managed object */
typedef struct Person1_store
{
	void (*delete_func)(Person1 **);	/* delete function pointer, NULL if no auto-delete */
	Person1 data;
} Person1_store;

/* Person1: create, destroy, set/clear autodelete */
Person1 * new_Person1 ( void )
{
	Person1_store *self_store = g_slice_new0( Person1_store );
	Person1 *self = (Person1 *) OBJREG_DATA_ADDR( self_store );
	
	autodelete_Person1( self, TRUE );

	register_object( (void*) self_store );

	return self;
}

void delete0_Person1 ( Person1 **pself )
{
	if ( *pself )
	{
		Person1_store *self_store = 
				(Person1_store *) OBJREG_STORE_ADDR( *pself );
		
		unregister_object( (void*) self_store );

		g_slice_free( Person1_store, self_store );

		*pself = NULL;
	}
}

void delete_Person1 ( Person1 *self )
{
	delete0_Person1( &self );
}

void autodelete_Person1 ( Person1 *self, BOOL autodelete )
{
	Person1_store *self_store = 
			(Person1_store *) OBJREG_STORE_ADDR( self );
	
	self_store->delete_func = autodelete ? delete0_Person1 : NULL;
}




/* data store for managed object */
typedef struct Person2_store
{
	void (*delete_func)(Person2 **);	/* delete function pointer, NULL if no auto-delete */
	Person2 data;
} Person2_store;

/* Person2: create, destroy, set/clear autodelete */
Person2 * new_Person2 ( void )
{
	Person2_store *self_store = g_slice_new0( Person2_store );
	Person2 *self = (Person2 *) OBJREG_DATA_ADDR( self_store );
	
	autodelete_Person2( self, TRUE );

	register_object( (void*) self_store );

	return self;
}

void delete0_Person2 ( Person2 **pself )
{
	if ( *pself )
	{
		Person2_store *self_store = 
				(Person2_store *) OBJREG_STORE_ADDR( *pself );
		
		unregister_object( (void*) self_store );

		g_slice_free( Person2_store, self_store );

		*pself = NULL;
	}
}

void delete_Person2 ( Person2 *self )
{
	delete0_Person2( &self );
}

void autodelete_Person2 ( Person2 *self, BOOL autodelete )
{
	Person2_store *self_store = 
			(Person2_store *) OBJREG_STORE_ADDR( self );
	
	self_store->delete_func = autodelete ? delete0_Person2 : NULL;
}




/* data store for managed object */
typedef struct Person3_store
{
	void (*delete_func)(Person3 **);	/* delete function pointer, NULL if no auto-delete */
	Person3 data;
} Person3_store;

/* Person3: create, destroy, set/clear autodelete */
Person3 * new_Person3 ( void )
{
	Person3_store *self_store = g_slice_new0( Person3_store );
	Person3 *self = (Person3 *) OBJREG_DATA_ADDR( self_store );
	
	autodelete_Person3( self, TRUE );

	register_object( (void*) self_store );

	return self;
}

void delete0_Person3 ( Person3 **pself )
{
	if ( *pself )
	{
		Person3_store *self_store = 
				(Person3_store *) OBJREG_STORE_ADDR( *pself );
		
		unregister_object( (void*) self_store );

		g_slice_free( Person3_store, self_store );

		*pself = NULL;
	}
}

void delete_Person3 ( Person3 *self )
{
	delete0_Person3( &self );
}

void autodelete_Person3 ( Person3 *self, BOOL autodelete )
{
	Person3_store *self_store = 
			(Person3_store *) OBJREG_STORE_ADDR( self );
	
	self_store->delete_func = autodelete ? delete0_Person3 : NULL;
}