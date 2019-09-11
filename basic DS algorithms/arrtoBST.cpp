Hello

I see that 2D Barcode stream is acceptable for MS Digital Frequent Flyer cards. It was implemented under PTR 13213573 [Serious]: ACM:LH:UAT:LH01652 QR barcode of digital FFP card could not be decoded.
 
We are getting decoding error in log attached:
https://loggingfacility.amadeus.com/v3/#/log-viewer/search-id/19032017837

Today, we dont have any specification document for MS Digital Frequent Flyer cards. But, as per our code , we are expecting "  " (two spaces) instead of "CS" in Airline Tier Level.

!Stream which caused error:
7FFPC001MS4006290282      AHMED               ABDALLA             MSS1120CSN      ^001'

*Stream expected by Decoding API:
7FFPC001MS4006290282      AHMED               ABDALLA             MSS1120  N      ^001'

When I ran the test after making changes in the stream, the decoding was successful.
Output after swiping the changed/corrected stream:


Decoder: decodeDocument&
**************************************&
FQTV card document:&
- Error Code : 0&
- Error String  : &
- Error Additionnal String  : &
- card number: 4006290282&
- holder's name: AHMED&
- expiration date: &
- issuing numeric carrier code: &
- issuing carrier name: MS&
- membership number is accurate: 1&
- given name or initials: ABDALLA&
- title: &
- holder's gender: U&
- issue date: &
- card type: &
- tier code: &
- alliance tier: SILVER&
- subsidiary type: U&
- seating preferences: &

!Please note that this is the decoded data that we send to CM, which is further manipulated by CM and sent in response (CSWPDR).

*With reference to the previous IR 16279553, today we only support two alliance tiers - SILVER (and not SILV) and GOLD, while decoding 2D barcode stream for Digital Frequent Flyer.

*Since adding Airline tier code is not a big change for us, we can consider it as PTR fix. 
!But MS needs to provide the exhaustive list of airline tier code because this is blank for all airlines today.