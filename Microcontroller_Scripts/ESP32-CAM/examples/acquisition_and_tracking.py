import src.COSMOS_AFS as COSMOS_AFS


def main():
    afs = COSMOS_AFS.COSMOS_AFS("http://192.168.4.2/capture")  # initialize class

    afs.acquisition()  # call once if state machine sets mode to Acquisition and Tracking


if __name__ == '__main__':
    main()

