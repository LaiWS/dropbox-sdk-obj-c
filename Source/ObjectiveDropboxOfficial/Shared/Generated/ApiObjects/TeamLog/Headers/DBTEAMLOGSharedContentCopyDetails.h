///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMLOGRelocateAssetReferencesLogInfo;
@class DBTEAMLOGSharedContentCopyDetails;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `SharedContentCopyDetails` struct.
///
/// Copied the shared file or folder to own Dropbox.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMLOGSharedContentCopyDetails : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// Shared content link.
@property (nonatomic, readonly, copy) NSString *sharedContentLink;

/// Sharing permission. Might be missing due to historical data gap.
@property (nonatomic, readonly, copy, nullable) NSString *sharingPermission;

/// Target asset index.
@property (nonatomic, readonly) NSNumber *targetIndex;

/// Specifies the source and destination indices in the assets list.
@property (nonatomic, readonly) DBTEAMLOGRelocateAssetReferencesLogInfo *relocateActionDetails;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param sharedContentLink Shared content link.
/// @param targetIndex Target asset index.
/// @param relocateActionDetails Specifies the source and destination indices in
/// the assets list.
/// @param sharingPermission Sharing permission. Might be missing due to
/// historical data gap.
///
/// @return An initialized instance.
///
- (instancetype)initWithSharedContentLink:(NSString *)sharedContentLink
                              targetIndex:(NSNumber *)targetIndex
                    relocateActionDetails:(DBTEAMLOGRelocateAssetReferencesLogInfo *)relocateActionDetails
                        sharingPermission:(nullable NSString *)sharingPermission;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
/// @param sharedContentLink Shared content link.
/// @param targetIndex Target asset index.
/// @param relocateActionDetails Specifies the source and destination indices in
/// the assets list.
///
/// @return An initialized instance.
///
- (instancetype)initWithSharedContentLink:(NSString *)sharedContentLink
                              targetIndex:(NSNumber *)targetIndex
                    relocateActionDetails:(DBTEAMLOGRelocateAssetReferencesLogInfo *)relocateActionDetails;

- (instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `SharedContentCopyDetails` struct.
///
@interface DBTEAMLOGSharedContentCopyDetailsSerializer : NSObject

///
/// Serializes `DBTEAMLOGSharedContentCopyDetails` instances.
///
/// @param instance An instance of the `DBTEAMLOGSharedContentCopyDetails` API
/// object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMLOGSharedContentCopyDetails` API object.
///
+ (nullable NSDictionary *)serialize:(DBTEAMLOGSharedContentCopyDetails *)instance;

///
/// Deserializes `DBTEAMLOGSharedContentCopyDetails` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMLOGSharedContentCopyDetails` API object.
///
/// @return An instantiation of the `DBTEAMLOGSharedContentCopyDetails` object.
///
+ (DBTEAMLOGSharedContentCopyDetails *)deserialize:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
