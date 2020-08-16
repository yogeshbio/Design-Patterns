#include <iostream>
#include <string>

/*
    1. Here Fileuploader is depending on low level module AwsCloud directly.
    2. Fileuploader is using the function uploadToS3Bucket() to upload to Aws

    However changing to Google Cloud can be a problem.
*/
struct AwsCloud {
   void uploadToS3Bucket(string filepath) { /* ... */ }
};

struct FileUploader {
   FileUploader(AwsCloud& awsCloud);
   void scheduleUpload(string filepath);
};


// Better solution
// 1. Provide abstract class with no particluar mention of S3 (to make it generic)
// 2. FileUploader now uses only Cloud instead of directy depending on Aws cloud
struct Cloud {
   virtual ~Cloud() = default;
   virtual void upload(string filepath) = 0;
};

struct AwsCloud {
   void upload(string filepath) override { /* ... */ }
};

struct FileUploader {
   FileUploader(Cloud& cloud);
   void scheduleUpload(string filepath);
};

