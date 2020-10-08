define(["require","exports","tslib","modules/clean/filepath","modules/clean/react/file_uploader/constants","modules/clean/filetypes","modules/clean/teams/content_manager_modern/path_util","modules/clean/react/file_uploader/utils","modules/clean/sharing/api/client","modules/clean/api_v2/types","modules/clean/sharing/access_level"],(function(e,t,r,a,n,s,c,o,i,l,u){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),a=r.__importStar(a),t.isPathInDirectory=function(e,t){return a.paths_are_equal(e,t)||a.inSubDirectory(e,t)},t.getUploadType=function(e,t){return a.normalize(e.dest)===a.normalize(t)?s.FileTypes.FILE:s.FileTypes.FOLDER},t.getRootPath=function(e,r){return t.getUploadType(e,r)===s.FileTypes.FOLDER?o.getRootDest(e,r):t.getFilePath(e)},t.getFilePath=function(e){return c.joinPathWithFileName({fqPath:e.dest,fileName:e.name})},t.getFileUploadsInPath=function(e,r){return e.filter((function(e){var n=t.getFilePath(e);return a.paths_are_equal(r,n)||a.inSubDirectory(r,n)}))},t.generateItemId=function(e,t){for(var r=e+t,a=0,n=0;n<r.length;n++)a=(a<<5)-a+r.charCodeAt(n)|0;return Math.abs(a).toString(36)},t.getModalFileList=function(e,a,s,c,i){return o.getFileUploadsWithStatus(e,[n.FileStatusType.PENDING,n.FileStatusType.UPLOADING]).reduce((function(e,n){var o=t.getUploadType(n,a),l=t.getRootPath(n,a);if(e.some((function(e){return e.file.fq_path===l}))||i&&o!==i)return e;var u=s.getTeamAccessLevel(l),d=t.generateItemId(l,c),h={batchId:n.batchId,itemId:d,teamAccessLevel:u,file:{type:o,fq_path:l,icon:""}};return r.__spreadArrays(e,[h])}),[])},t.removeTeamAccessToSharedFolder=function(e,t,a){return r.__awaiter(void 0,void 0,void 0,(function(){var n;return r.__generator(this,(function(r){switch(r.label){case 0:return r.trys.push([0,2,,3]),[4,e.removeMember({contentId:t,memberId:a})];case 1:return r.sent(),[2,!0];case 2:if(!(n=r.sent())||"no_permission"!==n[".tag"]&&"folder_owner"!==n[".tag"]&&"group_access"!==n[".tag"]&&"team_folder"!==n[".tag"]&&"other"!==n[".tag"])return[2,!0];throw n;case 3:return[2]}}))}))},t.addTeamAccessToSharedFolder=function(e,t,a,s){return r.__awaiter(void 0,void 0,void 0,(function(){var c,o,i;return r.__generator(this,(function(r){switch(r.label){case 0:c=t===n.TeamAccessLevel.READER?u.ACCESS_LEVEL.READER:u.ACCESS_LEVEL.WRITER,r.label=1;case 1:return r.trys.push([1,3,,7]),[4,e.updateMember({contentId:a,memberId:s,accessLevel:c})];case 2:return r.sent(),[3,7];case 3:return o=r.sent(),i=o.error,i&&i.member_error&&"no_explicit_access"===i.member_error[".tag"]?[4,e.addMembers({contentId:a,members:[new l.UnionScalar("dropbox_id",s)],accessLevel:c})]:[3,5];case 4:return r.sent(),[3,6];case 5:throw o;case 6:return[3,7];case 7:if(t!==n.TeamAccessLevel.WRITER)return[3,12];r.label=8;case 8:return r.trys.push([8,11,,12]),[4,e.relinquishMembership({contentId:a})];case 9:return r.sent(),[4,e.setConfidentiality({contentId:a,confidential:!1})];case 10:return r.sent(),[3,12];case 11:return r.sent(),[3,12];case 12:return[2]}}))}))},t.createSharedFolder=function(e){var a=e.user,c=e.uploadPath,o=e.file,l=e.teamAccessLevel,u=e.createdFolders,d=e.foldersWithError,h=e.autoTeamGroupId;return r.__awaiter(void 0,void 0,void 0,(function(){var e,m,f,_,p,v,T,g,I;return r.__generator(this,(function(r){switch(r.label){case 0:if(!l||l===n.TeamAccessLevel.INHERIT)return[2];if(d.some((function(e){return t.isPathInDirectory(e,o.dest)})))throw new Error("This file is in a folder with an upload error");if(e=t.getRootPath(o,c),m=new i.FolderShareApiClient({userId:a.id}),f=t.getUploadType(o,c),_=u.includes(e),p=![n.TeamAccessLevel.WRITER,n.TeamAccessLevel.INHERIT].includes(l),_||f!==s.FileTypes.FOLDER)return[3,12];v=void 0,r.label=1;case 1:return r.trys.push([1,3,,10]),[4,m.share({fqPath:e,folderPolicy:null,confidential:p})];case 2:return T=r.sent().shared_folder_id,v=T,[3,10];case 3:return g=r.sent(),I=g.error,I&&I.bad_path&&"already_shared"===I.bad_path[".tag"]?(v=I.bad_path.shared_folder_id,[n.TeamAccessLevel.READER,n.TeamAccessLevel.NO_ACCESS].includes(l)?[4,m.setConfidentiality({contentId:v,confidential:!0})]:[3,5]):[3,8];case 4:r.sent(),r.label=5;case 5:return l!==n.TeamAccessLevel.NO_ACCESS?[3,7]:[4,t.removeTeamAccessToSharedFolder(m,v,h)];case 6:r.sent(),r.label=7;case 7:return[3,9];case 8:throw g;case 9:return[3,10];case 10:return[n.TeamAccessLevel.READER,n.TeamAccessLevel.WRITER].includes(l)?[4,t.addTeamAccessToSharedFolder(m,l,v,h)]:[3,12];case 11:r.sent(),r.label=12;case 12:return[2]}}))}))}}));
//# sourceMappingURL=util.min.js-vflONsPol.map