/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef GS2_RANKING_GS2RANKINGPRIVATECLIENT_HPP_
#define GS2_RANKING_GS2RANKINGPRIVATECLIENT_HPP_

#include <gs2/ranking/Gs2RankingClient.hpp>
#include "control/CalcImmediateRequest.hpp"
#include <cstring>

namespace gs2 { namespace ranking {

typedef AsyncResult<void> AsyncCalcImmediateResult;

class Gs2RankingPrivateClient : public Gs2RankingClient
{
private:
    constexpr static const Char* ENDPOINT = "ranking";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2RankingPrivateClient(IGs2Credential& credential) :
        Gs2RankingClient(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2RankingPrivateClient(IGs2Credential& credential, const Region& region) :
        Gs2RankingClient(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2RankingPrivateClient(IGs2Credential& credential, const Char region[]) :
        Gs2RankingClient(credential, region)
    {
    }


    /**
     * ゲームモードを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void calcImmediate(std::function<void(AsyncCalcImmediateResult&)> callback, CalcImmediateRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/system/").append(detail::StringUtil::toStr(buffer, request.getOwnerId())).append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableId())).append("/mode/").append(detail::StringUtil::toStr(buffer, request.getGameMode())).append("/calcImmediate");
        }
        httpRequest.setRequestData("", 0);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_RANKING_GS2RANKINGPRIVATECLIENT_HPP_