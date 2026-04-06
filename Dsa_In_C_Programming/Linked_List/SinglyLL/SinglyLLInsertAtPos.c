/*

        Algorithm :

            START

                Create the node newn
                
                Initialize the data and initialize the next pointer to NULL
                
                Check if the linked list is empty or not
                
                if it is empty assign the address of newn in the head
                and if it is not empty then assign the address of the first node 
                to the next of the newn and assign the address of newn in the head

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
    //  Function Name : Insert_At_Last
    //  Description :   It is used to insert the element at last in the linked list        
    //  Author :        Tushar Vikas Bhore.
    //  Date :          06/04/2026
    //
    /////////////////////////////////////////////////////////////////////////////////

        void Insert_At_Last( PPNODE first , int iNo )
        {

            PNODE newn = NULL;
            PNODE temp = NULL;

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

                temp = *first;

                while( temp -> next != NULL )
                {

                    temp = temp -> next;

                }

                temp -> next = newn;

            }


        }// End Of The Insert_At_Last

    /////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : Insert_At_Pos
    //  Description :   It is used to insert the element at user asked position in the linked list        
    //  Author :        Tushar Vikas Bhore.
    //  Date :          06/04/2026
    //
    /////////////////////////////////////////////////////////////////////////////////

        void Insert_At_Pos( PPNODE first , int iNo , int iPos )
        {


            int iCount = 0;

            iCount = Count( *first );

            //  Invalid Position
            if( iPos < 1 || iPos > ( iCount + 1 )  )
            {

                printf( "\t\t\t\tInvalid Position.\n" );

                return ;

            }
            else if( iPos == 1 )    //  Insert at first
            {

                Insert_At_First( first , iNo );

            }
            else if( iPos == iCount + 1 ) //    Insert at last
            {

                Insert_At_Last( first , iNo );

            }
            else        //  Business Logic to insert at pos
            {
                
                PNODE temp = NULL;
                PNODE newn = NULL;

                newn = ( PNODE ) malloc ( sizeof ( NODE ) );

                newn -> iData = iNo;
                newn -> next = NULL;

                temp = *first;

                for( int iCnt = 1; iCnt < ( iPos - 1 ) ; iCnt++ )
                {

                    temp = temp -> next;

                }

                newn -> next = temp -> next;
                temp -> next = newn;

            }

        }
    
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

            Insert_At_Last( &head ,  151 );
            Insert_At_Last( &head ,  201 );
            Insert_At_Last( &head ,  251 );
            Insert_At_Last( &head ,  301 );

            printf("\n");
            printf("\t\t\t\t || OUTPUT OF Insert_At_Last || \t\t\t");
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

            Insert_At_Pos( &head , 45 , 3 );

            printf("\n");
            printf("\t\t\t\t || OUTPUT OF Insert_At_Pos || \t\t\t");
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
//                                 || OUTPUT OF Insert_At_Last ||
//                _______________________________________________________________
//
//                  | 11 | =>| 21 | =>| 51 | =>| 101 | =>| 151 | =>| 201 | =>| 251 | =>| 301 | =>NULL
//
//                   The number of node's in the linked list are : | 8 |.
//
//                _______________________________________________________________
//
//
//                                 || OUTPUT OF Insert_At_Pos ||
//                _______________________________________________________________
//
//                  | 11 | =>| 21 | =>| 45 | =>| 51 | =>| 101 | =>| 151 | =>| 201 | =>| 251 | =>| 301 | =>NULL
//
//                  The number of node's in the linked list are : | 9 |.
//
//                _______________________________________________________________
//
//
//
//
//
/////////////////////////////////////////////////////////////////

