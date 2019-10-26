/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculator.h"

bool_t
xdr_variable (XDR *xdrs, variable *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->x))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->y))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->ans))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->choice))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->x);
			IXDR_PUT_LONG(buf, objp->y);
			IXDR_PUT_LONG(buf, objp->ans);
			IXDR_PUT_LONG(buf, objp->choice);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->x))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->y))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->ans))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->choice))
				 return FALSE;
		} else {
			objp->x = IXDR_GET_LONG(buf);
			objp->y = IXDR_GET_LONG(buf);
			objp->ans = IXDR_GET_LONG(buf);
			objp->choice = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->x))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->y))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->ans))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->choice))
		 return FALSE;
	return TRUE;
}