/** @file BSTData.h
 *  @author Joseph Collora
 * 
 *  Description:
 *  - Interface for objects that defines comparison operators to compare data
 *    within the Binary Search Trees
 *  - Includes comparison operators (<,<=,>,>=,==,!=)
 *  - Includes no data members
 * 
 *  Implementation:
 *  - Methods implemented and overwritten by books/types and patrons (virtual)
 */

#ifndef BSTDATA_H
#define BSTDATA_H

#include <iostream>
#include <string>

using namespace std;

class BSTData {
public:
    virtual ~BSTData();

    // -------------------------------------------------------------------------
    /** display()
    * Display Info
    *
    * Display BSTData info into a string
    * Virtual function, can be overridden
    * @pre None.
    * @post None. const function
    * @return String representing info
    */
    virtual void display() const = 0;

    // -----------------------------------------------------------------------
    /** operator<()
     *  Less Than Operator
     * 
     * Determines if the left side item is less than the right
     * @pre Both items being compared exist
     * @post None.
     * @return true returned when left is less than right, false otherwise
     */
    virtual bool operator<(const BSTData& rhs) const;

    // -----------------------------------------------------------------------
    /** operator<=()
     *  Less Than or Equal Operator
     * 
     * Determines if the left side item is less than or equal to the right
     * @pre Both items being compared exist
     * @post None.
     * @return true returned when left is less than or equal to the right, false otherwise
     */
    virtual bool operator<=(const BSTData& rhs) const;

    // -----------------------------------------------------------------------
    /** operator>()
     *  Greater Than Operator
     * 
     * Determines of the left side item is greater than the right
     * @pre Both items being compared exist
     * @post None.
     * @return true returned when left is greater than right, false otherwise
     */
    virtual bool operator>(const BSTData& rhs) const;

    // -----------------------------------------------------------------------
    /** operator>=()
     *  Greater Than or Equal Operator
     * 
     * Determines of the left side item is greater than or equal to the right
     * @pre Both items being compared exist
     * @post None.
     * @return true returned when left is greater than or equal to right, 
     false otherwise
     */
    virtual bool operator>=(const BSTData& rhs) const;

    // -----------------------------------------------------------------------
    /** operator==()
     *  Equivalence Operator
     * 
     * Determines if the right and left items are equivalent
     * @pre Both items being compared exist
     * @post None.
     * @return true returned when left is equal to right, false otherwise
     */
    virtual bool operator==(const BSTData& rhs) const;

    // -----------------------------------------------------------------------
    /** operator==()
     *  Non-Equivelence Operator
     * 
     * Determines if the right and left items are not equivalent
     * @pre Both items being compared exist
     * @post None.
     * @return true returned when left is not equal to right, false otherwise
     */
    virtual bool operator!=(const BSTData& rhs) const;

protected:
    virtual int getComp(const BSTData& rhs) const = 0;
};

#endif