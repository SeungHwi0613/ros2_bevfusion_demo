import argparse
from os import path as osp
from data_converter import nuscenes_converter as nuscenes_converter
# from data_converter.create_gt_database import create_groundtruth_database


def nuscenes_data_prep(root_path, info_prefix, version, dataset_name, out_dir, max_sweeps=10, load_augmented=None):
    if load_augmented is None:
        nuscenes_converter.create_nuscenes_infos(root_path, info_prefix, version=version)


parser = argparse.ArgumentParser(description="Data converter arg parser")
parser.add_argument("dataset", metavar="nuscenes", help="name of the dataset")
parser.add_argument("--root-path", type=str, default="data/nuscenes", help="specify the root path of dataset")
parser.add_argument("--version", type=str, default="v1.0", required=False, help="specify the dataset version, no need for nuscenes")
parser.add_argument("--out-dir", type=str, default="data/nuscenes", required=False, help="name of info pkl")
parser.add_argument("--max-sweeps", type=int, default=10, required=False, help="specify sweeps of lidar per example")
parser.add_argument("--extra-tag", type=str, default="nuscenes")
parser.add_argument("--painted", default=False, action="store_true")
parser.add_argument("--virtual", default=False, action="store_true")
args = parser.parse_args()

if __name__ == "__main__":
    load_augmented = None
    if args.virtual:
        if args.painted: load_augmented = "mvp"
        else: load_augmented = "pointpainting"

    test_version = f"{args.version}-test"
    nuscenes_data_prep(
        root_path=args.root_path,
        info_prefix=args.extra_tag,
        version=test_version,
        dataset_name="NuScenesDataset",
        out_dir=args.out_dir,
        max_sweeps=args.max_sweeps,
        load_augmented=load_augmented,
    )