# Script for generating jazzy docs

if [ "$#" -ne 2 ]; then
    echo "Script requires two arguments: 1. version number and 2. path to docs repo checkout"
else
    sdk_version="$1"
    docs_repo_location="$2"

    echo "Checking doc repo exists..."

    if [ -d $docs_repo_location ]; then
        docs_location="$docs_repo_location/api-docs/$sdk_version"
        tmp_location="$docs_repo_location/api-docs/all_sdk_files"
        if [ -d $docs_location ]; then
            rm -rf $docs_location
        fi
        
        mkdir $docs_location

        if [ -d $tmp_location ]; then
            rm -rf $tmp_location
        fi
        mkdir $tmp_location

        echo "Copying all sdk files to tmp directory..."
        find ../Source/ObjectiveDropboxOfficial/ -name \*.[h,m] -exec cp {} $tmp_location \;
        cp ../README.md $tmp_location
        cp ./UmbrellaHeader.h $tmp_location

        echo "Generating documents..."
        jazzy --objc --readme $tmp_location/README.md --umbrella-header $tmp_location/UmbrellaHeader.h --framework-root $tmp_location --config ../.jazzy.json -o $docs_location

        cp jazzy.css $docs_location/css/

        echo "Removing tmp sdk files..."
        rm -rf $tmp_location

        cd $docs_repo_location/api-docs
        rm latest
        ln -s $sdk_version latest
        cd -
    else
        echo "Docs directory does not exist"
    fi
fi
