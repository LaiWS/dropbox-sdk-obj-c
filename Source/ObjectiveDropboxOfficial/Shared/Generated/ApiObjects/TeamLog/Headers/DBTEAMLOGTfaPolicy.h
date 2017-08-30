///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGTfaPolicy;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `TfaPolicy` union.
///
/// Two factor authentication policy
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGTfaPolicy : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBTEAMLOGTfaPolicyTag` enum type represents the possible tag states
/// with which the `DBTEAMLOGTfaPolicy` union can exist.
typedef NS_ENUM(NSInteger, DBTEAMLOGTfaPolicyTag) {
  /// (no description).
  DBTEAMLOGTfaPolicyDisabled,

  /// (no description).
  DBTEAMLOGTfaPolicyOptional,

  /// (no description).
  DBTEAMLOGTfaPolicyRequired,

  /// (no description).
  DBTEAMLOGTfaPolicyOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBTEAMLOGTfaPolicyTag tag;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "disabled".
///
/// @return An initialized instance.
///
- (instancetype)initWithDisabled;

///
/// Initializes union class with tag state of "optional".
///
/// @return An initialized instance.
///
- (instancetype)initWithOptional;

///
/// Initializes union class with tag state of "required".
///
/// @return An initialized instance.
///
- (instancetype)initWithRequired;

///
/// Initializes union class with tag state of "other".
///
/// @return An initialized instance.
///
- (instancetype)initWithOther;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Tag state methods

///
/// Retrieves whether the union's current tag state has value "disabled".
///
/// @return Whether the union's current tag state has value "disabled".
///
- (BOOL)isDisabled;

///
/// Retrieves whether the union's current tag state has value "optional".
///
/// @return Whether the union's current tag state has value "optional".
///
- (BOOL)isOptional;

///
/// Retrieves whether the union's current tag state has value "required".
///
/// @return Whether the union's current tag state has value "required".
///
- (BOOL)isRequired;

///
/// Retrieves whether the union's current tag state has value "other".
///
/// @return Whether the union's current tag state has value "other".
///
- (BOOL)isOther;

///
/// Retrieves string value of union's current tag state.
///
/// @return A human-readable string representing the union's current tag state.
///
- (NSString *)tagName;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `DBTEAMLOGTfaPolicy` union.
///
@interface DBTEAMLOGTfaPolicySerializer : NSObject

///
/// Serializes `DBTEAMLOGTfaPolicy` instances.
///
/// @param instance An instance of the `DBTEAMLOGTfaPolicy` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGTfaPolicy` API object.
///
+ (nullable NSDictionary *)serialize:(DBTEAMLOGTfaPolicy *)instance;

///
/// Deserializes `DBTEAMLOGTfaPolicy` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGTfaPolicy` API object.
///
/// @return An instantiation of the `DBTEAMLOGTfaPolicy` object.
///
+ (DBTEAMLOGTfaPolicy *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END