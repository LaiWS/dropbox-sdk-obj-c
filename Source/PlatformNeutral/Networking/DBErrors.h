///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///

#import <Foundation/Foundation.h>
@class DBAccessToken;
@class DBAUTHAuthError;
@class DBAUTHRateLimitError;

#pragma mark - HTTP error

///
/// Http request error.
///
/// Contains relevant information regarding a failed network
/// request. All error types except for DBOsError extend this
/// class as children. Initialized in the event of a generic,
/// unidentified HTTP error.
///
@interface DBRequestHttpError : NSObject

/// The Dropbox request id of the network call. This is useful to Dropbox
/// for debugging issues with Dropbox's SDKs and API. Please include the
/// value of this field when submitting technical support inquiries to
/// Dropbox.
@property(nonatomic, readonly, copy) NSString * _Nonnull requestId;

/// The HTTP response status code of the request.
@property(nonatomic, readonly, copy) NSNumber * _Nonnull statusCode;

/// A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the
/// "error_summary" key.
@property(nonatomic, readonly, copy) NSString * _Nonnull errorContent;

///
/// DBRequestHttpError full constructor.
///
/// @param requestId The Dropbox request id of the network call. This is
/// useful to Dropbox for debugging issues with Dropbox's SDKs and API.
/// @param statusCode The HTTP response status code of the request.
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
///
/// @return An initialized DBRequestHttpError instance.
///
- (nonnull instancetype)init:(NSString * _Nonnull)requestId
                  statusCode:(NSNumber * _Nonnull)statusCode
                errorContent:(NSString * _Nonnull)errorContent;

///
/// Description method.
///
/// @return A human-readable representation of the current DBRequestHttpError object.
///
- (NSString * _Nonnull)description;

@end

#pragma mark - Bad Input error

///
/// Bad Input request error.
///
/// Contains relevant information regarding a failed network
/// request. Initialized in the event of an HTTP 400 response.
/// Extends DBRequestHttpError.
///
@interface DBRequestBadInputError : DBRequestHttpError

///
/// DBRequestBadInputError full constructor.
///
/// @param requestId The Dropbox request id of the network call. This is
/// useful to Dropbox for debugging issues with Dropbox's SDKs and API.
/// @param statusCode The HTTP response status code of the request.
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
///
/// @return An initialized DBRequestBadInputError instance.
///
- (nonnull instancetype)init:(NSString * _Nonnull)requestId
                  statusCode:(NSNumber * _Nonnull)statusCode
                errorContent:(NSString * _Nonnull)errorContent;

///
/// Description method.
///
/// @return A human-readable representation of the current DBRequestBadInputError object.
///
- (NSString * _Nonnull)description;

@end

#pragma mark - Auth error

///
/// Auth request error.
///
/// Contains relevant information regarding a failed network
/// request. Initialized in the event of an HTTP 401 response.
/// Extends DBRequestHttpError.
///
@interface DBRequestAuthError : DBRequestHttpError

/// The structured object returned by the Dropbox API in the event of a 401 auth
/// error.
@property(nonatomic, readonly) DBAUTHAuthError * _Nonnull structuredAuthError;

///
/// DBRequestAuthError full constructor.
///
/// @param requestId The Dropbox request id of the network call. This is
/// useful to Dropbox for debugging issues with Dropbox's SDKs and API.
/// @param statusCode The HTTP response status code of the request.
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
/// @param structuredAuthError The structured object returned by the Dropbox API in the
/// event of a 401 auth error.
///
/// @return An initialized DBRequestAuthError instance.
///
- (nonnull instancetype)init:(NSString * _Nonnull)requestId
                  statusCode:(NSNumber * _Nonnull)statusCode
                errorContent:(NSString * _Nonnull)errorContent
         structuredAuthError:(DBAUTHAuthError * _Nonnull)structuredAuthError;

///
/// Description method.
///
/// @return A human-readable representation of the current DBRequestAuthError object.
///
- (NSString * _Nonnull)description;

@end

#pragma mark - Rate limit error

///
/// Rate limit request error.
///
/// Contains relevant information regarding a failed network
/// request. Initialized in the event of an HTTP 429 response.
/// Extends DBRequestHttpError.
///
@interface DBRequestRateLimitError : DBRequestHttpError

/// The structured object returned by the Dropbox API in the event of a 429
/// rate-limit error.
@property(nonatomic, readonly) DBAUTHRateLimitError * _Nonnull structuredRateLimitError;

/// The number of seconds to wait before making any additional requests in the
/// event of a rate-limit error.
@property(nonatomic, readonly, copy) NSNumber * _Nonnull backoff;

///
/// DBRequestRateLimitError full constructor.
///
/// @param requestId The Dropbox request id of the network call. This is
/// useful to Dropbox for debugging issues with Dropbox's SDKs and API.
/// @param statusCode The HTTP response status code of the request.
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
/// @param structuredRateLimitError The structured object returned by the Dropbox API in the
/// event of a 429 rate-limit error.
/// @param backoff The number of seconds to wait before making any additional requests in the
/// event of a rate-limit error.
///
/// @return An initialized DBRequestRateLimitError instance.
///
- (nonnull instancetype)init:(NSString * _Nonnull)requestId
                  statusCode:(NSNumber * _Nonnull)statusCode
                errorContent:(NSString * _Nonnull)errorContent
    structuredRateLimitError:(DBAUTHRateLimitError * _Nonnull)structuredRateLimitError
                     backoff:(NSNumber * _Nonnull)backoff;

///
/// Description method.
///
/// @return A human-readable representation of the current DBRequestRateLimitError object.
///
- (NSString * _Nonnull)description;

@end

#pragma mark - Internal Server error

///
/// Internal Server request error.
///
/// Contains relevant information regarding a failed network
/// request. Initialized in the event of an HTTP 500 response.
/// Extends DBRequestHttpError.
///
@interface DBRequestInternalServerError : DBRequestHttpError

///
/// Description method.
///
/// @return A human-readable representation of the current DBRequestInternalServerError object.
///
- (NSString * _Nonnull)description;

@end

#pragma mark - OS error

@interface DBRequestOsError : NSObject

/// A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the
/// "error_summary" key.
@property(nonatomic, readonly, copy) NSString * _Nonnull errorContent;

///
/// DBRequestOsError full constructor.
///
/// An example of such an error might be if you attempt to make a request and are
/// not connected to the internet.
///
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
///
/// @return An initialized DBRequestOsError instance.
///
- (nonnull instancetype)init:(NSString * _Nonnull)errorContent;

///
/// Description method.
///
/// @return A human-readable representation of the current DBRequestOsError object.
///
- (NSString * _Nonnull)description;

@end

#pragma mark - DBError generic error

///
/// Base class for generic network request error (as opposed to route-specific
/// error).
///
/// This class is represented almost like a Stone "Union" object. As one object,
/// it can represent a number of error "states" (see all of the values of
/// DBRequestErrorType). To handle each error type, call each of the
/// is<TAG_STATE> methods until you determine the current tag state, then
/// call the corresponding as<TAG_STATE> method to return an instance of the
/// appropriate error type.
///
/// For example:
///
/// @code
///
/// if ([dbxError isHTTPError]) {
///     DBHttpError *httpError = [dbxError asHttpError];
/// } else if ([dbxError isBadInputError]) { ........
///
/// @endcode
///
@interface DBError : NSObject

#pragma mark - Tag type definition

typedef NS_ENUM(NSInteger, DBRequestErrorType) {
  /// Errors produced at the HTTP layer.
  DBRequestHttpErrorType,

  /// Errors due to bad input parameters to an API Operation.
  DBRequestBadInputErrorType,

  /// Errors due to invalid authentication credentials.
  DBRequestAuthErrorType,

  /// Error caused by rate limiting.
  DBRequestRateLimitErrorType,

  /// Errors due to a problem on Dropbox.
  DBRequestInternalServerErrorType,

  /// Errors due to a problem on the local operating system.
  DBRequestOsErrorType,
};

#pragma mark - Instance variables

/// Current state of the DBError object type.
@property(nonatomic, readonly) DBRequestErrorType tag;

/// The Dropbox request id of the network call. This is useful to Dropbox
/// for debugging issues with Dropbox's SDKs and API. Please include the
/// value of this field when submitting technical support inquiries to
/// Dropbox.
@property(nonatomic, readonly, copy) NSString * _Nonnull requestId;

/// The HTTP response status code of the request.
@property(nonatomic, readonly, copy) NSNumber * _Nonnull statusCode;

/// A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the
/// "error_summary" key.
@property(nonatomic, readonly, copy) NSString * _Nonnull errorContent;

/// The structured object returned by the Dropbox API in the event of a 401 auth
/// error.
@property(nonatomic, readonly) DBAUTHAuthError * _Nonnull structuredAuthError;

/// The structured object returned by the Dropbox API in the event of a 429
/// rate-limit error.
@property(nonatomic, readonly) DBAUTHRateLimitError * _Nonnull structuredRateLimitError;

/// The number of seconds to wait before making any additional requests in the
/// event of a rate-limit error.
@property(nonatomic, readonly, copy) NSNumber * _Nonnull backoff;

#pragma mark - Constructors

///
/// DBError convenience constructor.
///
/// Initializes the DBError with all the required state for representing a generic
/// HTTP error.
///
/// @param requestId The Dropbox request id of the network call. This is
/// useful to Dropbox for debugging issues with Dropbox's SDKs and API.
/// @param statusCode The HTTP response status code of the request.
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
///
/// @return An initialized DBError instance HTTP error state.
///
- (nonnull instancetype)initAsHttpError:(NSString * _Nullable)requestId
                             statusCode:(NSNumber * _Nullable)statusCode
                           errorContent:(NSString * _Nullable)errorContent;

///
/// DBError convenience constructor.
///
/// Initializes the DBError with all the required state for representing a Bad
/// Input error.
///
/// @param requestId The Dropbox request id of the network call. This is
/// useful to Dropbox for debugging issues with Dropbox's SDKs and API.
/// @param statusCode The HTTP response status code of the request.
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
///
/// @return An initialized DBError instance with Bad Input error state.
///
- (nonnull instancetype)initAsBadInputError:(NSString * _Nullable)requestId
                                 statusCode:(NSNumber * _Nullable)statusCode
                               errorContent:(NSString * _Nullable)errorContent;

///
/// DBError convenience constructor.
///
/// Initializes the DBError with all the required state for representing an Auth
/// error.
///
/// @param requestId The Dropbox request id of the network call. This is
/// useful to Dropbox for debugging issues with Dropbox's SDKs and API.
/// @param statusCode The HTTP response status code of the request.
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
/// @param structuredAuthError The structured object returned by the Dropbox API in the
/// event of a 401 auth error.
///
/// @return An initialized DBError instance with Auth error state.
///
- (nonnull instancetype)initAsAuthError:(NSString * _Nullable)requestId
                             statusCode:(NSNumber * _Nullable)statusCode
                           errorContent:(NSString * _Nullable)errorContent
                    structuredAuthError:(DBAUTHAuthError * _Nonnull)structuredAuthError;

///
/// DBError convenience constructor.
///
/// Initializes the DBError with all the required state for representing a
/// Rate Limit error.
///
/// @param requestId The Dropbox request id of the network call. This is
/// useful to Dropbox for debugging issues with Dropbox's SDKs and API.
/// @param statusCode The HTTP response status code of the request.
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
/// @param structuredRateLimitError The structured object returned by the Dropbox API in the
/// event of a 429 rate-limit error.
/// @param backoff The number of seconds to wait before making any additional requests in the
/// event of a rate-limit error.
///
/// @return An initialized DBError instance.
///
- (nonnull instancetype)initAsRateLimitError:(NSString * _Nullable)requestId
                                  statusCode:(NSNumber * _Nullable)statusCode
                                errorContent:(NSString * _Nullable)errorContent
                    structuredRateLimitError:(DBAUTHRateLimitError * _Nonnull)structuredRateLimitError
                                     backoff:(NSNumber * _Nonnull)backoff;

///
/// DBError convenience constructor.
///
/// Initializes the DBError with all the required state for representing an
/// Internal Server error.
///
/// @param requestId The Dropbox request id of the network call. This is
/// useful to Dropbox for debugging issues with Dropbox's SDKs and API.
/// @param statusCode The HTTP response status code of the request.
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
///
/// @return An initialized DBError instance with Internal Server error state.
///
- (nonnull instancetype)initAsInternalServerError:(NSString * _Nullable)requestId
                                       statusCode:(NSNumber * _Nullable)statusCode
                                     errorContent:(NSString * _Nullable)errorContent;

///
/// DBError convenience constructor.
///
/// Initializes the DBError with all the required state for representing an "OS" error.
/// An example of such an error might be if you attempt to make a request and are not
/// connected to the internet.
///
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
///
/// @return An initialized DBError instance with OS error state.
///
- (nonnull instancetype)initAsOSError:(NSString * _Nullable)errorContent;

///
/// DBError full constructor.
///
/// @param requestId The Dropbox request id of the network call. This is
/// useful to Dropbox for debugging issues with Dropbox's SDKs and API.
/// @param statusCode The HTTP response status code of the request.
/// @param errorContent A string representation of the error body received in the reponse.
/// If for a route-specific error, this field will be the value of the "error_summary" key.
/// @param structuredAuthError The structured object returned by the Dropbox API in the
/// event of a 401 auth error.
/// @param structuredRateLimitError The structured object returned by the Dropbox API in the
/// event of a 429 rate-limit error.
/// @param backoff The number of seconds to wait before making any additional requests in the
/// event of a rate-limit error.
///
/// @return An initialized DBError instance.
///
- (nonnull instancetype)init:(DBRequestErrorType)tag
                   requestId:(NSString * _Nullable)requestId
                  statusCode:(NSNumber * _Nullable)statusCode
                errorContent:(NSString * _Nullable)errorContent
         structuredAuthError:(DBAUTHAuthError * _Nullable)structuredAuthError
    structuredRateLimitError:(DBAUTHRateLimitError * _Nullable)structuredRateLimitError
                     backoff:(NSNumber * _Nullable)backoff;

#pragma mark - Tag state methods

///
/// Retrieves whether the error's current tag state has value HttpError.
///
/// @return Whether the union's current tag state has value HttpError.
///
- (BOOL)isHttpError;

///
/// Retrieves whether the error's current tag state has value BadInputError.
///
/// @return Whether the union's current tag state has value BadInputError.
///
- (BOOL)isBadInputError;

///
/// Retrieves whether the error's current tag state has value AuthError.
///
/// @return Whether the union's current tag state has value AuthError.
///
- (BOOL)isAuthError;

///
/// Retrieves whether the error's current tag state has value RateLimitError.
///
/// @return Whether the union's current tag state has value RateLimitError.
///
- (BOOL)isRateLimitError;

///
/// Retrieves whether the error's current tag state has value InternalServerError.
///
/// @return Whether the union's current tag state has value InternalServerError.
///
- (BOOL)isInternalServerError;

///
/// Retrieves whether the error's current tag state has value OSError.
///
/// @return Whether the union's current tag state has value OSError.
///
- (BOOL)isOsError;

#pragma mark - Error subtype retrieval methods

///
/// Creates a DBRequestHttpError instance based on the data in the current DBError
/// instance.
///
/// @note Will throw error if current DBError instance tag state is not
/// HttpError. Should only use after checking if isHttpError returns true
/// for the current DBError instance.
///
/// @return An initialized DBRequestHttpError instance.
///
- (DBRequestHttpError * _Nonnull)asHttpError;

///
/// Creates a DBRequestBadInputError instance based on the data in the current DBError
/// instance.
///
/// @note Will throw error if current DBError instance tag state is not
/// BadInputError. Should only use after checking if isBadInputError returns true
/// for the current DBError instance.
///
/// @return An initialized DBRequestBadInputError.
///
- (DBRequestBadInputError * _Nonnull)asBadInputError;

///
/// Creates a DBRequestAuthError instance based on the data in the current DBError
/// instance.
///
/// @note Will throw error if current DBError instance tag state is not
/// AuthError. Should only use after checking if isAuthError returns true
/// for the current DBError instance.
///
/// @return An initialized DBRequestAuthError instance.
///
- (DBRequestAuthError * _Nonnull)asAuthError;

///
/// Creates a DBRequestRateLimitError instance based on the data in the current DBError
/// instance.
///
/// @note Will throw error if current DBError instance tag state is not
/// RateLimitError. Should only use after checking if isRateLimitError returns true
/// for the current DBError instance.
///
/// @return An initialized DBRequestRateLimitError instance.
///
- (DBRequestRateLimitError * _Nonnull)asRateLimitError;

///
/// Creates a DBRequestInternalServerError instance based on the data in the
/// current DBError instance.
///
/// @note Will throw error if current DBError instance tag state
/// is not InternalServerError. Should only use after checking if isInternalServerError
/// returns true for the current DBError instance.
///
/// @return An initialized DBHttpError instance.
///
- (DBRequestInternalServerError * _Nonnull)asInternalServerError;

///
/// Creates a DBRequestOsError instance based on the data in the current DBError
/// instance.
///
/// @note Will throw error if current DBError instance tag state is not
/// OsError. Should only use after checking if isOsError returns true
/// for the current DBError instance.
///
/// @return An initialized DBRequestOsError instance.
///
- (DBRequestOsError * _Nonnull)asOsError;

#pragma mark - Tag name method

///
/// Retrieves string value of union's current tag state.
///
/// @return A human-readable string representing the union's current tag
/// state.
///
- (NSString * _Nonnull)tagName;

#pragma mark - Description method

///
/// Description method.
///
/// @return A human-readable representation of the current DBError object.
///
- (NSString * _Nonnull)description;

@end