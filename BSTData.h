/** 
 * @file BSTData.h
 * @author Alex Lambert
 * 
 * Description:
 *   - Interface for objects that defines comparison operators to compare 
 * data within the Binary Search Trees
 *   - Includes comparison operators (<,<=,>,>=,==,!=)
 *   - Includes no data members
 * 
 * Assumptions/Implementation:
 *   - Inheriting classes must implement display and getComp
 *   - Uses getComp to compare BSTDatas of the same derived type
 */

#ifndef BSTDATA_H
#define BSTDATA_H

class BSTData {
public:
    //-----------------------------------------------------------------------
    /** ~BSTData()
     * Default Destructor
     *
     * Destroys the BSTData
     * @pre None
     * @post All memory used by the BSTData is deallocated
     */
    virtual ~BSTData();

    //-----------------------------------------------------------------------
    /** display()
     * Display Info
     *
     * Display BSTData info to cout
     * @pre None
     * @post None, const function
     */
    virtual void display() const = 0;

    //-----------------------------------------------------------------------
    /** operator<()
     * Less Than Operator
     * 
     * Determines if the left side item is less than the right
     * @pre Both items are of the same type
     * @post None.
     * @return true returned when left is less than right, false otherwise
     */
    virtual bool operator<(const BSTData& rhs) const;

    //-----------------------------------------------------------------------
    /** operator<=()
     * Less Than or Equal Operator
     * 
     * Determines if the left side item is less than or equal to the right
     * @pre Both items are of the same type
     * @post None.
     * @return true returned when left is less than or equal to the right, 
     * false otherwise
     */
    virtual bool operator<=(const BSTData& rhs) const;

    //-----------------------------------------------------------------------
    /** operator>()
     * Greater Than Operator
     * 
     * Determines of the left side item is greater than the right
     * @pre Both items are of the same type
     * @post None.
     * @return true returned when left is greater than right, false otherwise
     */
    virtual bool operator>(const BSTData& rhs) const;

    //-----------------------------------------------------------------------
    /** operator>=()
     * Greater Than or Equal Operator
     * 
     * Determines of the left side item is greater than or equal to the right
     * @pre Both items are of the same type
     * @post None.
     * @return true returned when left is greater than or equal to right, 
     * false otherwise
     */
    virtual bool operator>=(const BSTData& rhs) const;

    //-----------------------------------------------------------------------
    /** operator==()
     * Equivalence Operator
     * 
     * Determines if the right and left items are equivalent
     * @pre Both items are of the same type
     * @post None.
     * @return true returned when left is equal to right, false otherwise
     */
    virtual bool operator==(const BSTData& rhs) const;

    //-----------------------------------------------------------------------
    /** operator==()
     * Non-Equivelence Operator
     * 
     * Determines if the right and left items are not equivalent
     * @pre Both items are of the same type
     * @post None.
     * @return true returned when left is not equal to right, false otherwise
     */
    virtual bool operator!=(const BSTData& rhs) const;

protected:
    //-----------------------------------------------------------------------
    /** getComp()
     * Get Comparison
     * 
     * Returns the comparison value of this and rhs
     * @pre Both items are of the same type
     * @post None, no changes
     * @return -1 if this is smaller, 0 if equivalent, 1 is this is bigger
     */
    virtual int getComp(const BSTData& rhs) const = 0;
};

#endif