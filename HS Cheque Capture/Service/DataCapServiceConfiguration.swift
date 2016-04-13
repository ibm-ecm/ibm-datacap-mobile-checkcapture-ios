//
//  DataCapServiceConfiguration.swift
//  HS Cheque Capture
//
//  Created by Daniel Crow on 01/02/2016.
//  Copyright © 2016 Daniel Crow. All rights reserved.
//

import Foundation
import IBMCaptureSDK

class DataCapServiceConfiguration {

    private let stationId = "1"
    private let applicationId = "Transaction"
    private let workflowId = "Transaction"
    private let jobId = "Manual Select"
    private let dcoName = "Transaction"
    private let credential : NSURLCredential = NSURLCredential(user: "admin", password: "admin", persistence: .None)
    private var baseURL : NSURL = NSURL(string: "http://services-uscentral.skytap.com:8303/ServicewTM.svc")!
    
    private lazy var sessionManager:ICPSessionManager = { [unowned self] in
        if let sessionManager = self.capture.datacapSessionManagerForService(self.service, withCredential: self.credential) {
            return sessionManager
        }
        let sessionManager = ICPSessionManager(objectFactory: self.capture.objectFactory!, service: self.service, andCredentials: self.credential)
        return sessionManager
    }()
    
    private lazy var service:ICPDatacapService = {
        let service = (self.capture.objectFactory?.datacapServiceWithBaseURL(self.baseURL))!
        service.allowInvalidCertificates = true
        service.station = self.capture.objectFactory?.stationWithStationId(self.stationId, andIndex: 0, andDescription: "")
        service.application = self.capture.objectFactory?.applicationWithName(self.applicationId)
        service.workflow = self.capture.objectFactory?.workflowWithWorkflowId(self.workflowId, andIndex: 2)
        service.job = self.capture.objectFactory?.jobWithJobId(self.jobId, andIndex: 16)
        service.setupDCO = self.capture.objectFactory?.setupDCOWithName(self.dcoName)
        return service
    }()
    
    lazy var remoteComputationManager : ICPRemoteComputationManager = { [unowned self] in
        let remoteComputationManager = self.sessionManager.datacapRemoteComputationManager()
        return remoteComputationManager
    }()
    
    lazy var capture:ICPCapture = {
        return ICPCapture.instanceWithObjectFactoryType(.NonPersistent)!
    }()
    
    

}