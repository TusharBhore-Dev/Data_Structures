/*

        Algorithm :

            START

                Check if the linked list is empty or not
                
                if it is empty return 
                
                if it is not empty then store the address of second node in the head
                and delete the first node 

                Display the nodes and count of elements

            STOP


*/



    /////////////////////////////////////////////////////////////////
    // 
    //  Required Header files
    //
    /////////////////////////////////////////////////////////////////

        #include<stdio.h>
        #include<stdlib.h>

    //  To avoide the memory loss because of padding
        #pragma pack(1)

    //  Used Typedef to make the code readable
        typedef struct node NODE;
        typedef struct node * PNODE;
        typedef struct node ** PPNODE;

    //  User defined structure of node 
        struct node
        {

            int iData;
            struct node * next;

        };

    /////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : Insert_At_First
    //  Description :   It is used to insert the element at first in the linked list        
    //  Author :        Tushar Vikas Bhore.
    //  Date :          06/04/2026
    //
    /////////////////////////////////////////////////////////////////////////////////

        void Insert_At_First( PPNODE first , int iNo )
        {


            PNODE newn = NULL;

            newn = ( PNODE ) malloc ( sizeof ( NODE ) );

            newn -> iData = iNo;
            newn -> next = NULL;

            //  The Linked List Is Empty
            if( *first == NULL )
            {

                *first = newn;

            }
            else    //  The Linked List Contains AT least one or more nodes in it.
            {

                newn -> next = *first;
                *first = newn;

            }


        }// End Of The Insert_At_First

    
    /////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : Delete_At_First
    //  Description :   It is used to delete the element at first in the linked list        
    //  Author :        Tushar Vikas Bhore.
    //  Date :          06/04/2026
    //
    /////////////////////////////////////////////////////////////////////////////////

        void Delete_At_First( PPNODE first )
        {

            //  The Linked List Is Empty
            if( *first == NULL )
            {

                return;

            }
            else    //  The Linked List Contains AT least one or more nodes in it.
            {

                PNODE temp = NULL;

                temp = *first;
                
                *first = ( *first ) -> next;
                free( temp );

            }


        }// End Of The Delete_At_First

    
    /////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : Display
    //  Description :   It is used to display the elements in the linked list        
    //  Author :        Tushar Vikas Bhore.
    //  Date :          06/04/2026
    //
    /////////////////////////////////////////////////////////////////////////////////


        void Display( PNODE first )
        {

            printf("\t\t\t");

            while( first != NULL )
            {

                printf( "| %d | =>" , first -> iData  );

                first = first -> next;

            }

            printf( "NULL" );

        }// End Of Display
    
    /////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : Count
    //  Description :   It is used to count the elements in the linked list        
    //  Author :        Tushar Vikas Bhore.
    //  Date :          06/04/2026
    //
    /////////////////////////////////////////////////////////////////////////////////

        int Count( PNODE first )
        {

            int iCount = 0;

            while( first != NULL )
            {

                iCount++;

                first = first -> next;

            }

            return iCount;

        }// End Of Count

    /////////////////////////////////////////////////////////////////
    //
    //  Entry point function for the application
    //
    /////////////////////////////////////////////////////////////////

        int main()
        {

            PNODE head = NULL;

            int iRet = 0;

            Insert_At_First( &head , 101 );
            Insert_At_First( &head , 51 );
            Insert_At_First( &head , 21 );
            Insert_At_First( &head , 11 );

            printf("\n");
            printf("\t\t\t\t || OUTPUT OF Insert_At_First || \t\t\t");
            printf("\n");
            printf("\t\t_______________________________________________________________");
            printf("\n\n");

            Display( head );
            printf("\n");

            iRet = Count( head );

            printf("\n\t\t\tThe number of node's in the linked list are : | %d |. \n" , iRet);
            printf("\n");
            printf("\t\t_______________________________________________________________");
            printf("\n\n");

            Delete_At_First( &head );

            printf("\n");
            printf("\t\t\t\t || OUTPUT OF Insert_At_First || \t\t\t");
            printf("\n");
            printf("\t\t_______________________________________________________________");
            printf("\n\n");

            Display( head );
            printf("\n");

            iRet = Count( head );

            printf("\n\t\t\tThe number of node's in the linked list are : | %d |. \n" , iRet);
            printf("\n");
            printf("\t\t_______________________________________________________________");
            printf("\n\n");


            return 0;

        }// End Of main()

/////////////////////////////////////////////////////////////////
//
//  Testcase succesfully handaled by the application
//
//  TestCase 1 : 
//
//
//                                 || OUTPUT OF Insert_At_First ||
//                _______________________________________________________________
//
//                        | 11 | =>| 21 | =>| 51 | =>| 101 | =>NULL
//
//                        The number of node's in the linked list are : | 4 |.
//
//                _______________________________________________________________
//
//
//                                 || OUTPUT OF Insert_At_First ||
//                _______________________________________________________________
//
//                        | 21 | =>| 51 | =>| 101 | =>NULL
//
//                        The number of node's in the linked list are : | 3 |.
//
//                _______________________________________________________________
//
//
//
//
//
/////////////////////////////////////////////////////////////////

